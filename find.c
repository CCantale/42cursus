#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define END_COLOR "\e[0m"

#define TRUE 1
#define FALSE 0

enum
{
	e_FREE,
	e_DONT_FREE
};

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		printf("Malloc error!\n");
		exit(1);
	}
	else
		return (ptr);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	check_null(char **s1, char **s2)
{
	if (!*s1)
	{
		*s1 = ft_malloc(sizeof(char));
		**s1 = 0;
	}
	if (!*s2)
	{
		*s2 = ft_malloc(sizeof(char));
		**s2 = 0;
	}
}

char	*ft_strjoin(char *s1, char *s2, int free1, int free2)
{
	int	i;
	int	j;
	char	*join;
	
	check_null(&s1, &s2);
	join = (char *)ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		++i;
		++j;
	}
	join[i] = 0;
	if (free1 == e_FREE)
		ft_free(s1);
	if (free2 == e_FREE)
		ft_free(s2);
	return (join);
}

// joins together the 5 parts of the cmd: part1 + word + part2 + word + part3
char	*ft_cmd_join(char *part1, char *part2, char *part3, char *word)
{
	int	i;
	char	*join;
	
	if (!word)
		return (NULL);
	join = (char *)ft_malloc(sizeof(char) * (ft_strlen(part1) + ft_strlen(part2) + ft_strlen(part3) + ft_strlen(word) + 1));
	i = 0;
	return	(ft_strjoin(
				ft_strjoin(
						ft_strjoin(
								ft_strjoin(
										part1,
										word,
										e_DONT_FREE, e_DONT_FREE),
								part2,
								e_FREE, e_DONT_FREE),
						word,
						e_FREE, e_DONT_FREE),
				part3,
				e_FREE, e_DONT_FREE)
		);
}

/* lounches following cmd:
** (find . -name \"*.c\" -exec cat {} \\; | grep -E '\\.c  |", INPUT_FROM_USER') | ./find
** && (echo \"//////////////////////// HEADER FILES ////////////////////////\")
** && (find . -name \"*.h\" -exec cat {} \\; | grep -E '\\.h  |", INPUT_FROM_USER') | ./find
*/
void	ft_build_cmd(char *word)
{
	char	*cmd;

	cmd = ft_cmd_join(
			"(find . -name \"*.c\" -exec cat {} \\; | grep -E '\\.c  |",
			"') | ./find && (echo \"//////////////////////// HEADER FILES ////////////////////////\") && (find . -name \"*.h\" -exec cat {} \\; | grep -E '\\.h  |",
			"') | ./find",
			word
			);
	system(cmd);
	ft_free(cmd);
}

int	ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}

//gets next line from std input, which is supposed to be a pipe
char	*next_line(void)
{
	char	buff[2];
	char	*line;

	line = NULL;
	while (read(STDIN_FILENO, buff, 1) && *buff != '\n')
	{
		buff[1] = 0;
		line = ft_strjoin(line, buff, e_FREE, e_DONT_FREE);
	}
	return (line);
}

void	print(void)
{
	char	*line;

	line = next_line();
	while (line)
	{
		if (TRUE == ft_strncmp(line, "/* ", 3))
			printf(CYAN);
		else
			printf(YELLOW);
		printf("%s\n", line);
		printf(END_COLOR);
		ft_free(line);
		line = next_line();
	}
}

int	main(int argc, char **argv)
{
	if (TRUE == ft_strncmp(argv[1], "word", 4))
	{
		ft_build_cmd(argv[2]);
	}
	else
	{
		print();
	}
	return (0);
}

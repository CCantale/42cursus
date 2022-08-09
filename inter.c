#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	check(char *inter, char c)
{
	int	i;

	i = 0;
	while (inter[i])
	{
		if (inter[i] == c)
			return (1);
		++i;
	}
	return (0);
}

void	ft_inter(char *uno, char *due, char *inter)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (uno[i])
	{
		j = 0;
		while (due[j])
		{
			if (uno[i] == due[j] && check(inter, uno[i]))
				inter[k++] = uno[i];
			++j;
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	char	*inter;

	if (argc != 3)
		return (0);
	inter = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
	if (!inter)
		return (0);
	i = 0;
	while (i < ft_strlen(argv[1]) + 1)
		inter[i++] = 0;
	ft_inter(argv[1], argv[2], inter);
	write(1, inter, ft_strlen(inter));
	free(inter);
	return (0);
}


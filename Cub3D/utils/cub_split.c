#include "split.h"

static char	*make_next_chunk(char *str, char **str_ptr)
{
	size_t	i;
	char	*new_chunk;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	new_chunk = cub_substr(str, 0, i - 1);
	while (str[i] && str[i] == '\n')
		++i;
	*str_ptr += i;
	return (new_chunk);
}

static size_t	get_chunks_nbr(char *str)
{
	size_t	chunks_nbr;

	if (!str || !*str)
	{
		return (0);
	}
	chunks_nbr = 1;
	while (*str)
	{
		if (*str == '\n')
		{
			++chunks_nbr;
			while(*str == '\n')
				++str;
		}
		else
		{
			++str;
		}
	}
	return (chunks_nbr);
}

char	**cub_split(char *str)
{
	size_t	i;
	size_t	chunks_nbr;
	char	**split;

	while(*str == '\n')
		++str;
	chunks_nbr = get_chunks_nbr(str);
	split = ccantalloc(sizeof(char *), (chunks_nbr + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < chunks_nbr - 1)
	{
		split[i] = make_next_chunk(str, &str);
		if (!split[i])
		{
			cantalloc_clean();
			return(NULL);
		}
		++i;
	}
	return (split);
}

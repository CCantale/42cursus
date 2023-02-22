#include <stdlib.h>

char	*cub_strdup(char *str)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * (cub_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		++i;
	}
	dup[i] = 0;
	return (dup);
}

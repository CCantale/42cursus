#include <stdlib.h>
#include "../cantalloc/cantalloc.h"

void	*error_null(char *msg);
/* end of declarations */

char	*cub_substr(char *str, size_t start, size_t end)
{
	char	*substring;
	size_t	i;

	substring = cantalloc(sizeof(char) * (end - start + 2));
	if (!substring)
	{
		error_null("Malloc error");
	}
	i = 0;
	while (start <= end)
	{
		substring[i] = str[start];
		++start;
		++i;
	}
	substring[i] = 0;
	return (substring);
}

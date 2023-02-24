#include "../common.h"

int	cub_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (NOT_OK);
		++s1;
		++s2;
	}
	return (OK);
}

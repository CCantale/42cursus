#include <unistd.h>

void	*error_null(char *msg)
{
	write(2, "Error : ", 8);
	if (msg)
	{
		while (*msg)
			write(2, msg++, 1);
	}
	write(2, "\n", 1);
	return (NULL);
}

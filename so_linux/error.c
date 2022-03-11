#include "so_long.h"

void	*error_msg(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (NULL);
}

int	error_int(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (0);
}

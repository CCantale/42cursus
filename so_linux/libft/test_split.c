#include "libft.h"

int	main(int ac, char **av)
{
	char **matrix;

	if (ac != 2)
		return (ft_printf("One argument, please"));
	matrix = ft_split(av[1], 'k');
	ft_printf("%m", matrix);
	free(matrix);
	return (0);
}

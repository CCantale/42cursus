#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "stdfunc.h"
#include "libft.h"

void	test_isalpha(void)
{
	int	test1;
	int	test2;

	test1 = 49;
	test2 = 5;
	ft_putchar(test1);
	putstr("\n");
	putstr("isalpha = ");
	putnbr(isalpha(test1));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test1));
	putstr("\n\n");
	ft_putchar(test2);
	putstr("\n");
	putstr("isalpha = ");
	putnbr(isalpha(test2));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test2));
	putstr("\n\n");
}

void test_isdigit(void)
{
	int	test1;
	int	test2;

	test1 = 5;
	test2 = '5';
	putstr("(5)\nisdigit = ");
	putnbr(isdigit(test1));
	putstr(" | ft_isdigit = ");
	putnbr(ft_isdigit(test1));
	putstr("\n\n");
	putstr("(85)\nisdigit = ");
	putnbr(isdigit(test2));
	putstr(" | ft_isdigit = ");
	putnbr(ft_isdigit(test2));
	putstr("\n\n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	return (0);
}

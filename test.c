#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "stdfunc.h"
#include "libft.h"

void	test_isalpha(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = '1';
	test2 = 10;
	test3 = 'd';
	test4 = 'T';
	putstr("_ISALPHA\n(1)\nisalpha = ");
	putnbr(isalpha(test1));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test1));
	putstr("\n");
	putstr("(\\n)\nisalpha = ");
	putnbr(isalpha(test2));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test2));
	putstr("\n");
	putstr("(d)\nisalpha = ");
	putnbr(isalpha(test3));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test3));
	putstr("\n");
	putstr("(T)\nisalpha = ");
	putnbr(isalpha(test4));
	putstr(" | ft_isalpha = ");
	putnbr(ft_isalpha(test4));
	putstr("\n\n");
}

void	test_isdigit(void)
{
	int	test1;
	int	test2;

	test1 = 10;
	test2 = '5';
	putstr("_ISDIGIT\n(\\n)\nisdigit = ");
	putnbr(isdigit(test1));
	putstr(" | ft_isdigit = ");
	putnbr(ft_isdigit(test1));
	putstr("\n");
	putstr("(5)\nisdigit = ");
	putnbr(isdigit(test2));
	putstr(" | ft_isdigit = ");
	putnbr(ft_isdigit(test2));
	putstr("\n\n");
}

void	test_isalnum(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = '1';
	test2 = '\n';
	test3 = 'n';
	test4 = 'Q';
	putstr("_ISALNUM\n(1)\nisalnum = ");
	putnbr(isalnum(test1));
	putstr(" | ft_isalnum = ");
	putnbr(ft_isalnum(test1));
	putstr("\n");
	putstr("(\\n)\nisalnum = ");
	putnbr(isalnum(test2));
	putstr(" | ft_isalnum = ");
	putnbr(ft_isalnum(test2));
	putstr("\n");
	putstr("(n)\nisalnum = ");
	putnbr(isalnum(test3));
	putstr(" | ft_isalnum = ");
	putnbr(ft_isalnum(test3));
	putstr("\n");
	putstr("(Q)\nisalnum = ");
	putnbr(isalnum(test4));
	putstr(" | ft_isalnum = ");
	putnbr(ft_isalnum(test4));
	putstr("\n\n");
}

void	test_isascii(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = -5;
	test2 = 42;
	test3 = 127;
	test4 = 128;
	putstr("_ISASCII\n(-5)\nisascii = ");
	putnbr(isascii(test1));
	putstr(" | ft_isascii = ");
	putnbr(ft_isascii(test1));
	putstr("\n");
	putstr("(42)\nisascii = ");
	putnbr(isascii(test2));
	putstr(" | ft_isascii = ");
	putnbr(ft_isascii(test2));
	putstr("\n");
	putstr("(127)\nisascii = ");
	putnbr(isascii(test3));
	putstr(" | ft_isascii = ");
	putnbr(ft_isascii(test3));
	putstr("\n");
	putstr("(128)\nisascii = ");
	putnbr(isascii(test4));
	putstr(" | ft_isascii = ");
	putnbr(ft_isascii(test4));
	putstr("\n\n");
}

void	test_isprint(void)
{
	int	test1;
	int	test2;

	test1 = 127;
	test2 = ' ';
	putstr("_ISPRINT\n(\\n)\nisprint = ");
	putnbr(isprint(test1));
	putstr(" | ft_isprint = ");
	putnbr(ft_isprint(test1));
	putstr("\n");
	putstr("(5)\nisprint = ");
	putnbr(isprint(test2));
	putstr(" | ft_isprint = ");
	putnbr(ft_isprint(test2));
	putstr("\n\n");
}

void	test_strlen(void)
{
	char	*test1;
	char	*test2;

	test1 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "Test!");
	test2 = (char *)malloc(sizeof(char) * 1);
	ft_strcpy(test2, "\0");
	putstr("_STRLEN\n(\"Test!\")\nstrlen = ");
	putnbr(strlen(test1));
	putstr(" | ft_strlen = ");
	putnbr(ft_strlen(test1));
	putstr("\n");
	putstr("(NULL)\nstrlen = ");
	putnbr(strlen(test2));
	putstr(" | ft_strlen = ");
	putnbr(ft_strlen(test2));
	putstr("\n\n");
	free(test1);
	free(test2);
}

void	test_memset(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "Test!");
	putstr("_MEMSET(a, 4)\n(\"Test!\")\nmemset = ");
	putstr(memset(test1, 'a', 4));
	putstr(" | ft_memset = ");
	ft_strcpy(test1, "Test!");
	putstr(ft_memset(test1, 'a', 4));
	free(test1);
	putstr("\n\n");
}

void	test_bzero(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "Test!");
	putstr("_BZERO(str + 2, 3)\n(\"Test!\")\nbzero = ");
	bzero(test1 + 2, 3);
	putstr(test1);
	putstr(" | ft_bzero = ");
	ft_strcpy(test1, "Test!");
	ft_bzero(test1 + 2, 4);
	putstr(test1);
	free(test1);
	putstr("\n\n");
}

void	test_memcpy(void)
{
	char	*test1;
	char	*test2;

	test1 = (char *)malloc(sizeof(char) * 6);
	test2 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "Test!");
	ft_strcpy(test2, "Bella");
	putstr("_MEMCPY\n(\"Test!\", \"Bella\", 3)\nmemcpy = ");
	test1 = memcpy(test1, test2, 3);
	putstr(test1);
	putstr(" | ft_memcpy = ");
	ft_strcpy(test1, "Test!");
	test1 = ft_memcpy(test1, test2, 3);
	putstr(test1);
	free(test1);
	free(test2);
	putstr("\n\n");
}

void	test_memmove(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 15);
	ft_strcpy(test1, "test_memmove()");
	putstr("_MEMMOVE\n(\"test_memmove()\", test + 5, 5)\nmemmove = ");
	memmove(test1, test1 + 5, 5);
	putstr(test1);
	ft_strcpy(test1, "test_memmove()");
	putstr(" | ft_memmove = ");
	ft_memmove(test1, test1 + 5, 5);
	putstr(test1);
	free(test1);
	putstr("\n\n");
}

void	test_strlcpy(void)
{
	char	*test1;
	char	*test2;

	test1 = (char *)malloc(sizeof(char) * 15);
	test2 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "test_strlcpy()");
	ft_strcpy(test2, "Test!");
	putstr("_STRLCPY\n(\"test_strlcpy()\"(+ 3), \"Test!\", 6)\nstrlcpy = ");
	strlcpy(test1 + 3, test2, 6);
	putstr(test1);
	ft_strcpy(test1, "test_strlcpy()");
	putstr(" | ft_strlcpy = ");
	ft_strlcpy(test1 + 3, test2, 6);
	putstr(test1);
	free(test1);
	free(test2);
	putstr("\n\n");
}

void	test_strlcat(void)
{
	char	*test1;
	char	*test2;
	size_t	size;

	test1 = (char *)malloc(sizeof(char) * 21);
	test2 = (char *)malloc(sizeof(char) * 6);
	ft_strcpy(test1, "test_strlcat()");
	ft_strcpy(test2, "Test!");
	putstr("_STRLCAT\n(\"test_strlcpy()\", \"Test!\", 21)\nstrlcat = ");
	size = strlcat(test1, test2, 21);
	putstr(test1);
	putstr(" ");
	putnbr(size);
	ft_strcpy(test1, "test_strlcpy()\0\0\0\0\0\0");
	putstr(" | ft_strlcat = ");
	size = ft_strlcat(test1, test2, 21);
	putstr(test1);
	putstr(" ");
	putnbr(size);
	putstr("\n(\"test_strlcpy()\", \"Test!\", 6)\nstrlcat = ");
	ft_strcpy(test1, "test_strlcpy()\0\0\0\0\0\0");
	size = strlcat(test1, test2, 6);
	putstr(test1);
	putstr(" ");
	putnbr(size);
	ft_strcpy(test1, "test_strlcpy()\0\0\0\0\0\0");
	putstr(" | ft_strlcat = ");
	size = ft_strlcat(test1, test2, 6);
	putstr(test1);
	putstr(" ");
	putnbr(size);
	free(test1);
	free(test2);
	putstr("\n\n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	return (0);
}

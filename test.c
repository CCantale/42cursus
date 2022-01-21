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

void	test_toupper(void)
{
	int		a;
	int		five;

	a = 'a';
	five = '5';
	putstr("_TOUPPER\n(a)\ntoupper = ");
	putnbr(toupper(a));
	putstr(" ");
	ft_putchar(toupper(a));
	putstr(" | ft_toupper = ");
	putnbr(ft_toupper(a));
	putstr(" ");
	ft_putchar(ft_toupper(a));
	putstr("\n");
	putstr("(5)\ntoupper = ");
	putnbr(toupper(five));
	putstr(" ");
	ft_putchar(toupper(five));
	putstr(" | ft_toupper = ");
	putnbr(ft_toupper(five));
	putstr(" ");
	ft_putchar(ft_toupper(five));
	putstr("\n\n");
}

void	test_tolower(void)
{
	int	a;
	int	five;

	a = 'A';
	five = '5';
	putstr("_TOLOWER\n(A)\ntoupper = ");
	putnbr(tolower(a));
	putstr(" ");
	ft_putchar(tolower(a));
	putstr(" | ft_tolower = ");
	putnbr(ft_tolower(a));
	putstr(" ");
	ft_putchar(ft_tolower(a));
	putstr("\n");
	putstr("(5)\ntolower = ");
	putnbr(tolower(five));
	putstr(" ");
	ft_putchar(tolower(five));
	putstr(" | ft_tolower = ");
	putnbr(ft_tolower(five));
	putstr(" ");
	ft_putchar(ft_tolower(five));
	putstr("\n\n");
}

void	test_strchr(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 15);
	ft_strcpy(test1, "test_strchr()");
	putstr("_STRCHR\n(\"test_strchr()\", 'r')\nstrchr = ");
	putstr(strchr(test1, 'r'));
	putstr(" | ft_strchr = ");
	putstr(ft_strchr(test1, 'r'));
	putstr("\n");
	putstr("(\"test_strchr()\", 0)\nstrchr = ");
	putstr(strchr(test1, 0));
	putstr(" | ft_strchr = ");
	putstr(ft_strchr(test1, 0));
	free(test1);
	putstr("\n\n");
}

void	test_strrchr(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 16);
	ft_strcpy(test1, "test_strrchr()");
	putstr("_STRRCHR\n(\"test_strrchr()\", 's')\nstrrchr = ");
	putstr(strrchr(test1, 's'));
	putstr(" | ft_strrchr = ");
	putstr(ft_strrchr(test1, 's'));
	putstr("\n");
	putstr("(\"test_strrchr()\", 0)\nstrrchr = ");
	putstr(strrchr(test1, 0));
	putstr(" | ft_strrchr = ");
	putstr(ft_strrchr(test1, 0));
	free(test1);
	putstr("\n\n");
}

void	test_strncmp(void)
{
	putstr("_STRNCMP\n(\"test_strncmp()\", \"test_strncmp()\", 13)\nstrncmp = ");
	putnbr(strncmp("test_strncmp()", "test_strncmp()", 13));
	putstr(" | ft_strncmp = ");
	putnbr(ft_strncmp("test_strncmp()", "test_strncmp()", 13));
	putstr("\n(\"test_strncmp()\", \"test_st42rncmp()\", 13)\nstrncmp = ");
	putnbr(strncmp("test_strncmp()", "test_st42rncmp()", 13));
	putstr(" | ft_strncmp = ");
	putnbr(ft_strncmp("test_strncmp()", "test_st42rncmp()", 13));
	putstr("\n[Basta che siano entrambi positivi, negativi o nulli]");
	putstr("\n\n");
}

void	test_memchr(void)
{
	putstr("_MEMCHR\n(\"test_memchr()\", 'm', 9)\nmemchr = ");
	putstr(memchr("test_memchr()", 'm', 9));
	putstr(" | ft_memchr = ");
	putstr(ft_memchr("test_memchr()", 'm', 9));
//	putstr("\n(\"test_memchr()\", 'm', 3)\nmemchr = ");
//	putstr(memchr("test_memchr()", 'm', 3));
//	putstr(" | ft_memchr = ");
//	putstr(ft_memchr("test_memchr()", 'm', 3));
//	putstr("\n(\"test_memchr()\", 'm', 0)\nmemchr = ");
//	putstr(memchr("test_memchr()", 'm', 0));
//	putstr(" | ft_memchr = ");
//	putstr(ft_memchr("test_memchr()", 'm', 0));
	putstr("\n\n");
}

void	test_memcmp(void)
{
	putstr("_MEMCMP\n(\"test_memcmp()\", \"test_memcmp()\", 13)\nmemcmp = ");
	putnbr(memcmp("test_memcmp()", "test_memcmp()", 13));
	putstr(" | ft_memcmp = ");
	putnbr(ft_memcmp("test_memcmp()", "test_memcmp()", 13));
	putstr("\n(\"test_memcmp()\", \"test_me42mcmp()\", 15)\nmemcmp = ");
	putnbr(memcmp("test_memcmp()", "test_me42mcmp()", 15));
	putstr(" | ft_memcmp = ");
	putnbr(ft_memcmp("test_memcmp()", "test_me42mcmp()", 15));
	putstr("\n[Basta che siano entrambi positivi, negativi o nulli]");
	putstr("\n(\"test_memcmp()\", \"test_me42mcmp()\", 0)\nmemcmp = ");
	putnbr(memcmp("test_memcmp()", "test_me42mcmp()", 0));
	putstr(" | ft_memcmp = ");
	putnbr(ft_memcmp("test_memcmp()", "test_me42mcmp()", 0));
	putstr("\n\n");
}

void	test_strnstr(void)
{
	putstr("_STRNSTR\n(\"test_strnstr()\", \"str\", 14)\nstrnstr = ");
	putstr(strnstr("test_strnstr()", "str", 14));
	putstr(" | ft_strnstr = ");
	putstr(ft_strnstr("test_strnstr()", "str", 14));
//	putstr("\n(\"test_strnstr()\", \"str\", 4)\nstrnstr = ");
//	putstr(strnstr("test_strnstr()", "str", 4));
//	putstr(" | ft_strnstr = ");
//	putstr(ft_strnstr("test_strnstr()", "str", 4));
//	putstr("\n(\"test_strnstr()\", \"0\", 4)\nstrnstr = ");
//	putstr(strnstr("test_strnstr()", "\0", 4));
//	putstr(" | ft_strnstr = ");
//	putstr(ft_strnstr("test_strnstr()", "\0", 4));
//	putstr(ft_strnstr("test_strnstr()", "str", 0));
//	putstr("\n(\"test_strnstr()\", \"str\", 0)\nstrnstr = ");
//	putstr(strnstr("test_strnstr()", "str", 0));
//	putstr(" | ft_strnstr = ");
	putstr("\n\n");
}

void	test_atoi(void)
{
	putstr("_ATOI\n(4862)\natoi = ");
	putnbr(atoi("4862"));
	putstr(" | ft_atoi = ");
	putnbr(ft_atoi("4862"));
	putstr("\n(2147483648)\natoi = ");
	putnbr(atoi("2147483648"));
	putstr(" | ft_atoi = ");
	putnbr(ft_atoi("2147483648"));
	putstr("\n(-2147483649)\natoi = ");
	putnbr(atoi("-2147483649"));
	putstr(" | ft_atoi = ");
	putnbr(ft_atoi("-2147483649"));
	putstr("\n\n");
}

void	test_strdup(void)
{
	putstr("_STRDUP\n(test_strdup())\nstrdup = ");
	putstr(strdup("test_strdup()"));
	putstr(" | ft_strdup = ");
	putstr(ft_strdup("test_strdup()"));
	putstr("\n\n");
}

void	test_substr(void)
{
	char	*test1;

	test1 = (char *)malloc(sizeof(char) * 13);
	ft_strcpy(test1, "test_substr()");
	putstr("_SUBSTR\nft_substr(\"test_substr()\", 3, 5) = ");
	putstr(ft_substr(test1, 3, 5));
	putstr("\nft_substr(\"test_substr()\", 7, 10) = ");
	putstr(ft_substr(test1, 7, 10));
	putstr("\n\n");
}

void	test_strjoin(void)
{
	putstr("_STRJOIN\nft_strjoin(\"test_\", \"strjoin()\") = ");
	putstr(ft_strjoin("test_", "strjoin()"));
	putstr("\n\n");
}

void	test_strtrim(void)
{
	putstr("_STRTRIM\n(ft_strtrim(\"+-ociao+-o\", \"o+-\") = ");
	putstr(ft_strtrim("+-ociao+-o", "o+-"));
	putstr("\n\n");
}

void	test_split(void)
{
	int		i;
	char	**split;

	split = ft_split("--1-2--3---4----5-----42", '-');
	putstr("_SPLIT\nft_split(\"--1-2--3---4----5-----42\", \'-\') =\n");
	putstr(*split);
	putstr("\n");
	putstr(*(split + 1));
	putstr("\n");
	putstr(*(split + 2));
	putstr("\n");
	putstr(*(split + 3));
	putstr("\n");
	putstr(*(split + 4));
	putstr("\n");
	putstr(*(split + 5));
	putstr("\n");
	i = 0;
	while (*(split + i))
	   ++i;
	putnbr(i);	
	if (!*(split + 6))
		putstr("\nOk!");
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
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	return (0);
}

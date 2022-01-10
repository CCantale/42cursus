#include "stdfunc.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		write(1, str + i, 1);
		++i;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			dest[i] = '\0';
		++i;
	}
	return (dest);
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) 
		ft_putchar(nb + 48);
}


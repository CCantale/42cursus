/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:53:37 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/15 20:34:59 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0 || needle == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack + i && i < len)
	{
		j = 0;
		while (*haystack + i + j == *needle + j && i + j < len)
		{
			if (*needle + j + 1 == 0)
				return ((char *)haystack + i);
			++j;
		}
		++i;
	}
	return (NULL);
}

int	main(void)
{
	putstr("_STRNSTR\n(\"test_strnstr()\", \"str\", 14)\nstrnstr = ");
	putstr(strnstr("test_strnstr()", "str", 14));
	putstr(" | ft_strnstr = ");
	putstr(ft_strnstr("test_strnstr()", "str", 14));
	putstr("\n(\"test_strnstr()\", \"str\", 4)\nstrnstr = ");
	putstr(strnstr("test_strnstr()", "str", 4));
	putstr(" | ft_strnstr = ");
	putstr(ft_strnstr("test_strnstr()", "str", 4));
	putstr("\n(\"test_strnstr()\", \"0\", 4)\nstrnstr = ");
	putstr(strnstr("test_strnstr()", "\0", 4));
	putstr(" | ft_strnstr = ");
	putstr(ft_strnstr("test_strnstr()", "\0", 4));
	putstr(ft_strnstr("test_strnstr()", "str", 0));
	putstr("\n(\"test_strnstr()\", \"str\", 0)\nstrnstr = ");
	putstr(strnstr("test_strnstr()", "str", 0));
	putstr(" | ft_strnstr = ");
	putstr("\n\n");
	return (0);
}

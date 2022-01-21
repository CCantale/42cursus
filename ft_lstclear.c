/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:00:22 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/21 12:25:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*old;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		old = (*lst) -> next;
		ft_lstdelone(*lst, del);
		*lst = old;
	}
	lst = NULL;
}


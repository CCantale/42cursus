/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:25 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/21 12:52:19 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst -> content));
	lst = lst -> next;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
		{
			ft_lstclear(&new_lst, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		lst = lst -> next;
	}
	return (new_lst);
}


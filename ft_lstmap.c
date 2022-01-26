/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:25 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/26 16:34:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!f || !del || !lst)
		return (NULL);
	head = NULL;
	while (lst)
	{
		tail = ft_lstnew(f(lst -> content));
		if (!tail)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tail);
		lst = lst -> next;
	}
	return (head);
}

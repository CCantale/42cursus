#include "cantalloc.h"

static t_alloc	*new_node(void	*ptr)
{
	t_alloc	*node;

	node = malloc(sizeof(t_alloc));
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}

static void	clean_garbage_list(t_alloc *head)
{
	t_alloc	*tmp;

	tmp = head;
	while (tmp)
	{
		head = head->next;
		free(tmp->ptr);
		free(tmp);
		tmp = head;
	}
}

static void	*cantalloc_handler(size_t size, int mode)
{
	static t_alloc	*garbage_head;
	static t_alloc	*garbage_tail;
	void		*new_ptr;

	if (mode == NEW)
	{
		new_ptr = malloc(size);
		if (!new_ptr)
			return (NULL);
		if (!garbage_head)
		{
			garbage_head = new_node(new_ptr);
			garbage_tail = garbage_head;
		}
		else
		{
			garbage_tail->next = new_node(new_ptr);
			garbage_tail = garbage_tail->next;
		}
		return (new_ptr);
	}
	else if (mode == CLEAN)
	{
		clean_garbage_list(garbage_head);
	}
	return (NULL);
}

void	*cantalloc(size_t size)
{
	return (cantalloc_handler(size, NEW));
}

void	*ccantalloc(size_t size, size_t count)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = cantalloc_handler(size * count, NEW);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		new_ptr[i] = 0;
		++i;
	}
	return ((void *)new_ptr);
}

void	cantalloc_clean(void)
{
	cantalloc_handler(0, CLEAN);
}

#ifndef CANTALLOC_H
# define CANTALLOC_H

# include <stdlib.h>

# define NEW	0
# define CLEAN	1

/* garbage collector node */
typedef struct s_alloc
{
	void		*ptr;
	struct s_alloc	*next;
}	t_alloc;

/* Allocates size bytes of memory with malloc() and saves
** the pointer in a static linked list, before returning it.
** Returns NULL if malloc fails. */
void	*cantalloc(size_t size);

/* Allocates size * count bytes of memory with malloc(), fills
** everything with 0s and saves the pointer in a static linked list,
** before returning it. Returns NULL if malloc fails.*/
void	*ccantalloc(size_t size, size_t count);

/* Frees all the memory previously allocated by cantalloc and ccantalloc. */
void	cantalloc_clean(void);

#endif

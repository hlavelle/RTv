#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *a;

	a = malloc(size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}

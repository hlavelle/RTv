#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a;
	const char	*b;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	a = dest;
	b = src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}

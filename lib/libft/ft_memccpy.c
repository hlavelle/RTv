#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*a;
	unsigned char	*b;

	i = 0;
	a = (char *)dest;
	b = (unsigned char *)src;
	while (i < n)
	{
		a[i] = *b;
		if (*b == (unsigned char)c)
			return (dest + i + 1);
		b++;
		i++;
	}
	return (NULL);
}

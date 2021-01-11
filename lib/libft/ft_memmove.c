#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char*)dest;
	s = (char*)src;
	if (dest == src)
		return (dest);
	if (s < d && s + n > d)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}

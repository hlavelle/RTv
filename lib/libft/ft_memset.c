#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (s);
}

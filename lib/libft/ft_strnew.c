#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	if (size + 1 < size)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_bzero(a, size + 1);
	return (a);
}

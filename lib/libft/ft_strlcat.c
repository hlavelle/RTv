#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t a;
	size_t result;

	i = 0;
	a = 0;
	result = 0;
	while (a < size && dst[a] != '\0')
	{
		a++;
		result++;
	}
	while (a + 1 < size && src[i] != '\0')
	{
		dst[a] = src[i];
		a++;
		i++;
	}
	if (a < size)
		dst[a] = '\0';
	return (ft_strlen(src) + result);
}

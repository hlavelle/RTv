#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *b;

	b = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			b = (char *)s;
		s++;
	}
	if (*s == c)
		b = (char *)s;
	return (b);
}

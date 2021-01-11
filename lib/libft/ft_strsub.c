#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	unsigned int	x;

	x = 0;
	i = start;
	if (!s)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	while (i < start + len)
	{
		a[x] = s[i];
		i++;
		x++;
	}
	a[x] = '\0';
	return (a);
}

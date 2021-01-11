#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*a;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}

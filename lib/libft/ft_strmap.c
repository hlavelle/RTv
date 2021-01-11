#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = f(s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}

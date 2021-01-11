#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (a == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		a[i] = *s2;
		s2++;
		i++;
	}
	a[i] = '\0';
	return (a);
}

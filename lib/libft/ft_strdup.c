#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 1;
	while (s[i] != '\0')
	{
		i++;
		a++;
	}
	str = (char *)malloc(sizeof(char) * (a));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		str[i] = *(char *)s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

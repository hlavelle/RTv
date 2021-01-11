#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	char	*a_final;
	int		i;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	if (j < i)
		return (ft_strnew(0));
	if (!(a = ft_strnew(j - i + 1)))
		return (NULL);
	a_final = a;
	while (i <= j)
	{
		*a = s[i];
		i++;
		a++;
	}
	return (a_final);
}

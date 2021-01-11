#include "libft.h"

static	size_t	ft_index_find(const char *big, const char *little, \
		size_t len, size_t i)
{
	size_t	j;

	j = 0;
	while (little[j] != '\0' && i < len && big[i] == little[j])
	{
		i++;
		j++;
	}
	return (j);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (!little[ft_index_find(big, little, len, i)])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

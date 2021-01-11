#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	l;

	if (*needle == '\0')
		return (char*)haystack;
	l = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (!ft_strncmp(haystack, needle, l))
			return (char*)(haystack);
		haystack++;
	}
	return (0);
}

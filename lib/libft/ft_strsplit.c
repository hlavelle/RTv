#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != c && s[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static int	ft_countchars(char const *s, char c)
{
	int b;
	int i;

	b = 1;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		b++;
		i++;
	}
	return (b);
}

static char	*ft_write_str(char *a, char const *s, int n)
{
	int i;

	i = 0;
	n = n - 1;
	while (i < n)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		y;

	y = 0;
	if (!s || !(a = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			a[y] = (char *)malloc(sizeof(char) * (ft_countchars(s, c)));
			if (a[y] == NULL)
			{
				ft_free_all(a, y - 1);
				return (NULL);
			}
			a[y] = ft_write_str(&a[y][0], s, ft_countchars(s, c));
			y++;
			s = s + ft_countchars(s, c) - 1;
		}
	}
	a[y] = NULL;
	return (a);
}

#include "libft.h"

static char	*ft_putstrinitoa(int n, char *a)
{
	if (n == -2147483648)
	{
		a[0] = '-';
		a[1] = '2';
		return (ft_putstrinitoa(147483648, a + 2));
	}
	if (n < 0)
	{
		*a = '-';
		++a;
		n = -n;
	}
	if (n / 10 != 0)
		a = ft_putstrinitoa(n / 10, a);
	*a = n % 10 + '0';
	++a;
	*a = '\0';
	return (a);
}

char		*ft_itoa(int n)
{
	char	*a;
	int		b;
	int		count;

	b = 0;
	count = ft_ten_count(n);
	if (n <= 0)
		b = 1;
	a = (char *)malloc(sizeof(char) * (count + b + 1));
	if (a == NULL)
		return (NULL);
	ft_putstrinitoa(n, a);
	return (a);
}

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	long	a;
	int		x;

	a = 0;
	x = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\r' ||
	*nptr == '\t' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		x = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr - '0' <= 9 && *nptr - '0' >= 0)
	{
		a = a * 10 + (*nptr - '0');
		if (a < 0 && x < 0)
			return (0);
		if (a < 0 && x > 0)
			return (-1);
		nptr++;
	}
	return (a * x);
}

#include "libft.h"

void	ft_free_all(char **a, int y)
{
	while (y >= 0)
	{
		free(a[y]);
		y--;
	}
	free(a);
}

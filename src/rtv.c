#include "../include/rtv1.h"

int	main(int argc, char **argv)
{
	t_rtv	rtv;
	int		res;

	check_input(argc, argv, &rtv);
	init_rtv(&rtv);
	ray(&rtv);
	res = rtv_loop(&rtv);
	free_rtv(&rtv);
	return (res);
}

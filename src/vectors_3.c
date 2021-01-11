#include "../include/rtv1.h"

t_vec	minus_num_vec(t_vec a, t_vec b)
{
	a = mult_by_num(a, -1);
	return (sum_vec(a, b));
}

t_vec	sum_vec(t_vec a, t_vec b)
{
	t_vec	res;

	res = (t_vec){a.x + b.x, a.y + b.y, a.z + b.z};
	return (res);
}

t_vec	mult_by_num(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

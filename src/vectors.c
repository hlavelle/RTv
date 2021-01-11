#include "../include/rtv1.h"

t_vec	sub_vec(t_vec a, t_vec b)
{
	t_vec	res;

	res = (t_vec){a.x - b.x, a.y - b.y, a.z - b.z};
	return (res);
}

double	scal_mult_vec(t_vec a, t_vec b)
{
	double	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

t_vec	norm_vec(t_vec a)
{
	double	n;

	n = 1.0 / pow((a.x * a.x + a.y * a.y + a.z * a.z), 0.5);
	a = (t_vec) {a.x * n, a.y * n, a.z * n};
	return (a);
}

t_vec	mult_vec_num(t_vec a, double num)
{
	t_vec res;

	res = (t_vec) {a.x * num, a.y * num, a.z * num};
	return (res);
}

double	len_vec(t_vec a)
{
	double	res;

	res = pow((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)), 0.5);
	return (res);
}

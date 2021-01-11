#include "../include/rtv1.h"

t_vec	div_vec_num(t_vec a, double num)
{
	t_vec res;

	res.x = a.x / num;
	res.y = a.y / num;
	res.z = a.z / num;
	return (res);
}

t_vec	cyl_normal
	(t_vec inter_point, t_obj *closest_obj, t_rtv *rtv, double closest_t)
{
	t_vec	normal;
	t_vec	oc;
	double	m;

	oc = sub_vec(rtv->inter.pos_vec, closest_obj->pos);
	m = scal_mult_vec(rtv->inter.dir_vec, closest_obj->pos) * closest_t\
		+ scal_mult_vec(oc, closest_obj->rot);
	normal = norm_vec(sub_vec(sub_vec(inter_point, closest_obj->pos),\
	mult_by_num(closest_obj->rot, m)));
	return (normal);
}

t_vec	cone_normal
	(t_vec inter_point, t_obj *closest_obj, t_rtv *rtv, double closest_t)
{
	t_vec	normal;
	t_vec	oc;
	double	k;
	double	m;

	k = 1 + tan(closest_obj->size) * tan(closest_obj->size);
	oc = sub_vec(rtv->inter.pos_vec, closest_obj->pos);
	m = scal_mult_vec(rtv->inter.dir_vec, closest_obj->pos) * closest_t\
		+ scal_mult_vec(oc, closest_obj->rot);
	normal = norm_vec(sub_vec(sub_vec(inter_point, closest_obj->pos),\
		mult_by_num(closest_obj->rot, m * k)));
	return (normal);
}

t_vec	calculate_normal
	(t_rtv *rtv, t_obj *closest_obj, t_vec inter_point, double closest_t)
{
	if (closest_obj->type == SPHERE)
		return (norm_vec(sub_vec(inter_point, closest_obj->pos)));
	else if (closest_obj->type == PLANE)
		return (norm_vec(closest_obj->rot));
	else if (closest_obj->type == CYLINDER)
		return (cyl_normal(inter_point, closest_obj, rtv, closest_t));
	else if (closest_obj->type == CONE)
		return (cone_normal(inter_point, closest_obj, rtv, closest_t));
	else
		return (norm_vec(closest_obj->rot));
}

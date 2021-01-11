#include "../include/rtv1.h"

double	intersection(t_rtv *rtv, t_obj **closest_obj)
{
	double	closest_t;
	t_obj	*obj_lst;

	obj_lst = rtv->objs;
	closest_t = rtv->inter.max;
	while (obj_lst)
	{
		if (obj_lst->type == SPHERE)
			sphere_intersection(rtv, obj_lst, closest_obj, &closest_t);
		else if (obj_lst->type == PLANE)
			plane_intersection(rtv, obj_lst, closest_obj, &closest_t);
		else if (obj_lst->type == CYLINDER)
			cyl_intersection(rtv, obj_lst, closest_obj, &closest_t);
		else if (obj_lst->type == CONE)
			cone_intersection(rtv, obj_lst, closest_obj, &closest_t);
		obj_lst = obj_lst->next;
	}
	return (closest_t);
}

double	compute_light(t_rtv *rtv, double closest_t, t_obj *closest_obj)
{
	double	i;
	t_light	*light;
	t_vec	l;
	double	scal;
	t_obj	*other_obj;

	i = rtv->ambient;
	light = rtv->light;
	while (light)
	{
		l = norm_vec(sub_vec(light->pos,
			sum_vec(mult_vec_num(rtv->d, closest_t), rtv->cam.pos)));
		scal = scal_mult_vec(calculate_normal(rtv, closest_obj,
		sum_vec(mult_vec_num(rtv->d, closest_t), rtv->cam.pos), closest_t), l);
		init_intesection_struct(rtv, FOR_SHADOW,
			sum_vec(mult_vec_num(rtv->d, closest_t), rtv->cam.pos),
			sub_vec(light->pos, sum_vec(mult_vec_num(rtv->d, closest_t),
			rtv->cam.pos)));
		other_obj = NULL;
		intersection(rtv, &other_obj);
		if (scal > 0 && !other_obj)
			i += light->intens * scal;
		light = light->next;
	}
	return (i);
}

int		trace_ray(t_rtv *rtv)
{
	double	closest_t;
	t_color	color;
	t_obj	*closest_obj;
	int		res_col;
	double	i;

	closest_obj = NULL;
	init_intesection_struct(rtv, FOR_RAY, rtv->cam.pos, rtv->d);
	closest_t = intersection(rtv, &closest_obj);
	if (closest_t >= RAY_MAX || !closest_obj)
	{
		color = (t_color){0, 0, 0};
		return ((color.r << 16) + (color.b << 8) + (color.g));
	}
	i = compute_light(rtv, closest_t, closest_obj);
	i = i / 100 > 1 ? 1 : i / 100;
	res_col = ((int)(closest_obj->col.r * i) << 16) +
	((int)(closest_obj->col.g * i) << 8) + closest_obj->col.b * i;
	return (res_col);
}

void	ray(t_rtv *rtv)
{
	int	x;
	int	y;
	int	*colors;

	colors = (int *)rtv->surface->pixels;
	y = (WIN_HEIGHT / 2);
	while (y > -WIN_HEIGHT / 2)
	{
		x = -(WIN_WIDTH / 2);
		while (x < WIN_WIDTH / 2)
		{
			rtv->d = (t_vec){x * 1.0 / WIN_WIDTH, y * 1.0 / WIN_HEIGHT, 1.0};
			rtv->d = norm_vec(rotate_vec(rtv->cam.dir, rtv->d));
			colors[(WIN_WIDTH / 2 + x) + (WIN_HEIGHT / 2 - y) *
				WIN_WIDTH] = trace_ray(rtv);
			x++;
		}
		y--;
	}
	SDL_UpdateWindowSurface(rtv->window);
}

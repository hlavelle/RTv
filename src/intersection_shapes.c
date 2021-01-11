#include "../include/rtv1.h"

void	sphere_intersection
	(t_rtv *rtv, t_obj *sphere, t_obj **closest_obj, double *closest_t)
{
	double a;
	double b;
	double c;
	double roots[3];
	double discr;

	a = scal_mult_vec(rtv->inter.dir_vec, rtv->inter.dir_vec);
	b = 2 * scal_mult_vec(sub_vec(rtv->inter.pos_vec, sphere->pos),
		rtv->inter.dir_vec);
	c = scal_mult_vec(sub_vec(rtv->inter.pos_vec, sphere->pos),
		sub_vec(rtv->inter.pos_vec, sphere->pos)) - sphere->size * sphere->size;
	discr = b * b - 4 * a * c;
	roots[0] = discr < 0 ? rtv->inter.max : ((-b + pow(discr, 0.5)) / (2 * a));
	roots[1] = discr < 0 ? rtv->inter.max : ((-b - pow(discr, 0.5)) / (2 * a));
	roots[2] = (roots[0] < roots[1]) && (roots[0] >= rtv->inter.min) ?\
	roots[0] : roots[1];
	if (*closest_t > roots[2] && roots[2] >= rtv->inter.min)
	{
		*closest_t = roots[2];
		*closest_obj = sphere;
	}
}

void	plane_intersection
	(t_rtv *rtv, t_obj *plane, t_obj **closest_obj, double *closest_t)
{
	t_vec	oc;
	double	roots[3];

	oc = sub_vec(rtv->inter.pos_vec, plane->pos);
	roots[0] = scal_mult_vec(oc, plane->rot);
	roots[1] = scal_mult_vec(rtv->inter.dir_vec, plane->rot);
	roots[2] = -roots[0] / roots[1];
	if (*closest_t > roots[2] && roots[2] >= rtv->inter.min)
	{
		*closest_t = roots[2];
		*closest_obj = plane;
	}
}

void	cyl_intersection
	(t_rtv *rtv, t_obj *cyl, t_obj **closest_obj, double *closest_t)
{
	double a;
	double b;
	double c;
	double roots[3];
	double discr;

	a = scal_mult_vec(rtv->inter.dir_vec, rtv->inter.dir_vec) -\
	pow(scal_mult_vec(rtv->inter.dir_vec, cyl->rot), 2.0);
	b = 2 *
	(scal_mult_vec(sub_vec(rtv->inter.pos_vec, cyl->pos), rtv->inter.dir_vec) -
	((scal_mult_vec(rtv->inter.dir_vec, cyl->rot) *
		scal_mult_vec(sub_vec(rtv->inter.pos_vec, cyl->pos), cyl->rot))));
	c = scal_mult_vec(sub_vec(rtv->inter.pos_vec, cyl->pos),
	sub_vec(rtv->inter.pos_vec, cyl->pos)) - cyl->size * cyl->size -
	pow(scal_mult_vec(sub_vec(rtv->inter.pos_vec, cyl->pos), cyl->rot), 2.0);
	discr = b * b - 4 * a * c;
	roots[0] = discr < 0 ? rtv->inter.max : ((-b + pow(discr, 0.5)) / (2 * a));
	roots[1] = discr < 0 ? rtv->inter.max : ((-b - pow(discr, 0.5)) / (2 * a));
	roots[2] = (roots[0] < roots[1]) && (roots[0] >= rtv->inter.min) ?\
	roots[0] : roots[1];
	if (*closest_t > roots[2] && roots[2] >= rtv->inter.min)
	{
		*closest_t = roots[2];
		*closest_obj = cyl;
	}
}

void	cone_intersection
	(t_rtv *rtv, t_obj *cone, t_obj **closest_obj, double *closest_t)
{
	double a;
	double b;
	double c;
	double roots[3];
	double k;

	k = 1 + tan(cone->size) * tan(cone->size);
	a = scal_mult_vec(rtv->inter.dir_vec, rtv->inter.dir_vec) -\
	k * pow(scal_mult_vec(rtv->inter.dir_vec, cone->rot), 2.0);
	b = 2 * (scal_mult_vec(sub_vec(rtv->inter.pos_vec, cone->pos),
		rtv->inter.dir_vec) - k * ((scal_mult_vec(rtv->inter.dir_vec, cone->rot)
		* scal_mult_vec(sub_vec(rtv->inter.pos_vec, cone->pos), cone->rot))));
	c = scal_mult_vec(sub_vec(rtv->inter.pos_vec, cone->pos),
	sub_vec(rtv->inter.pos_vec, cone->pos)) - k *
	pow(scal_mult_vec(sub_vec(rtv->inter.pos_vec, cone->pos), cone->rot), 2.0);
	k = b * b - 4 * a * c;
	roots[0] = k < 0 ? rtv->inter.max : ((-b + pow(k, 0.5)) / (2 * a));
	roots[1] = k < 0 ? rtv->inter.max : ((-b - pow(k, 0.5)) / (2 * a));
	roots[2] = (roots[0] < roots[1]) && (roots[0] >= rtv->inter.min) ?\
	roots[0] : roots[1];
	if (*closest_t > roots[2] && roots[2] >= rtv->inter.min)
	{
		*closest_t = roots[2];
		*closest_obj = cone;
	}
}

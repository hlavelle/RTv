#include "../include/rtv1.h"

void	get_sphere(t_rtv *rtv)
{
	t_obj *sphere;

	if (arr_len(rtv->buf) != 5)
		exit_with_message("Invalid sphere info", 0, rtv);
	if (!(sphere = new_obj(rtv->objs)))
		exit_with_message("Can`t malloc obj", 0, rtv);
	rtv->objs = rtv->objs == NULL ? sphere : rtv->objs;
	sphere->pos = record_vec_from_str(rtv->buf[1], rtv);
	sphere->rot = record_vec_from_str(rtv->buf[2], rtv);
	sphere->col = record_color_from_str(rtv->buf[3], rtv);
	sphere->size = ft_atoi(rtv->buf[4]);
	if (sphere->size <= 0 || sphere->size > 5000)
		exit_with_message("Invalid sphere's radius info", 0, rtv);
	sphere->type = SPHERE;
}

void	get_cone(t_rtv *rtv)
{
	t_obj *cone;

	if (arr_len(rtv->buf) != 5)
		exit_with_message("Invalid cone info", 0, rtv);
	if (!(cone = new_obj(rtv->objs)))
		exit_with_message("Can`t malloc obj", 0, rtv);
	rtv->objs = rtv->objs == NULL ? cone : rtv->objs;
	cone->pos = record_vec_from_str(rtv->buf[1], rtv);
	cone->rot = record_vec_from_str(rtv->buf[2], rtv);
	cone->rot = rotate_vec(cone->rot, (t_vec){0, 1, 0});
	cone->col = record_color_from_str(rtv->buf[3], rtv);
	cone->size = (double)ft_atoi(rtv->buf[4]) * (M_PI / 180);
	if (cone->size <= 0 || cone->size > 180)
		exit_with_message("Invalid cone's radius info", 0, rtv);
	cone->type = CONE;
}

void	get_cyl(t_rtv *rtv)
{
	t_obj *cyl;

	if (arr_len(rtv->buf) != 5)
		exit_with_message("Invalid cylinder info", 0, rtv);
	if (!(cyl = new_obj(rtv->objs)))
		exit_with_message("Can`t malloc obj", 0, rtv);
	rtv->objs = rtv->objs == NULL ? cyl : rtv->objs;
	cyl->pos = record_vec_from_str(rtv->buf[1], rtv);
	cyl->rot = record_vec_from_str(rtv->buf[2], rtv);
	cyl->rot = rotate_vec(cyl->rot, (t_vec){0, 1, 0});
	cyl->col = record_color_from_str(rtv->buf[3], rtv);
	cyl->size = ft_atoi(rtv->buf[4]);
	if (cyl->size <= 0 || cyl->size > 5000)
		exit_with_message("Invalid cylinder's radius info", 0, rtv);
	cyl->type = CYLINDER;
}

void	get_plane(t_rtv *rtv)
{
	t_obj *plane;

	if (arr_len(rtv->buf) != 4)
		exit_with_message("Invalid plane info", 0, rtv);
	if (!(plane = new_obj(rtv->objs)))
		exit_with_message("Can`t malloc obj", 0, rtv);
	rtv->objs = rtv->objs == NULL ? plane : rtv->objs;
	plane->pos = record_vec_from_str(rtv->buf[1], rtv);
	plane->rot = record_vec_from_str(rtv->buf[2], rtv);
	if (plane->rot.x == 0 && plane->rot.y == 0 && plane->rot.z == 0)
		exit_with_message("Invalid plane info", 0, rtv);
	plane->col = record_color_from_str(rtv->buf[3], rtv);
	plane->type = PLANE;
}

#include "../include/rtv1.h"

void	get_camera(t_rtv *rtv)
{
	if (arr_len(rtv->buf) != 3)
		exit_with_message("Invalid camera info", 0, rtv);
	rtv->cam.pos = record_vec_from_str(rtv->buf[1], rtv);
	rtv->cam.dir = record_vec_from_str(rtv->buf[2], rtv);
}

void	get_light(t_rtv *rtv)
{
	t_light *light;

	if (arr_len(rtv->buf) != 3)
		exit_with_message("Invalid light info", 0, rtv);
	if (!(light = new_light(rtv->light)))
		exit_with_message("Can`t malloc light", 0, rtv);
	rtv->light = rtv->light == NULL ? light : rtv->light;
	light->pos = record_vec_from_str(rtv->buf[1], rtv);
	light->intens = ft_atoi(rtv->buf[2]);
}

void	get_ambient_light(t_rtv *rtv)
{
	if (arr_len(rtv->buf) != 2)
		exit_with_message("Invalid ambient light info", 0, rtv);
	rtv->ambient += ft_atoi(rtv->buf[1]);
	if (rtv->ambient < 0 || rtv->ambient > 50)
		exit_with_message("Invalid ambient light info", 0, rtv);
}

void	record_line_info(t_rtv *rtv)
{
	if (!(ft_strcmp(rtv->buf[0], "camera:")))
		get_camera(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "sphere:")))
		get_sphere(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "plane:")))
		get_plane(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "cylinder:")))
		get_cyl(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "cone:")))
		get_cone(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "light:")))
		get_light(rtv);
	else if (!(ft_strcmp(rtv->buf[0], "ambient:")))
		get_ambient_light(rtv);
	else
		exit_with_message("Invalid input", 0, rtv);
}

void	read_input_file(t_rtv *rtv)
{
	int		fd;
	char	*line;

	fd = open(rtv->config_file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		rtv->buf = ft_strsplit(line, ' ');
		free(line);
		rtv->buf == NULL ?\
		exit_with_message("Can`t split input line", 0, rtv) : 0;
		record_line_info(rtv);
		rtv->buf = free_char_arr(rtv->buf);
	}
	free(line);
}

#include "../include/rtv1.h"

void	init_sdl(t_rtv *rtv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		exit_with_message("Can`t init SDL", 0, rtv);
	rtv->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (rtv->window == NULL)
		exit_with_message("Can`t init SDL", 0, rtv);
	if (!(rtv->surface = SDL_GetWindowSurface(rtv->window)))
		exit_with_message("Can`t init SDL", 0, rtv);
}

void	init_intesection_struct(t_rtv *rtv, int purpose, t_vec pos, t_vec dir)
{
	if (purpose == FOR_RAY)
	{
		rtv->inter.max = RAY_MAX;
		rtv->inter.min = RAY_MIN;
	}
	if (purpose == FOR_SHADOW)
	{
		rtv->inter.max = len_vec(dir);
		rtv->inter.min = SHADOW_MIN;
	}
	rtv->inter.pos_vec = pos;
	rtv->inter.dir_vec = norm_vec(dir);
}

void	init_struct_rtv(t_rtv *rtv, char *path)
{
	rtv->window = NULL;
	rtv->surface = NULL;
	rtv->config_file_path = path;
	rtv->run = 1;
	rtv->buf = NULL;
	rtv->cam.pos = (t_vec){0.0, 0.0, 0.0};
	rtv->cam.dir = (t_vec){0.0, 0.0, 0.0};
	rtv->d = (t_vec){0.0, 0.0, 0.0};
	rtv->objs = NULL;
	rtv->light = NULL;
	rtv->ambient = 10.0;
}

void	init_rtv(t_rtv *rtv)
{
	init_sdl(rtv);
	read_input_file(rtv);
}

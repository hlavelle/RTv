#include "../include/rtv1.h"

void	free_rtv(t_rtv *rtv)
{
	rtv->window ? SDL_DestroyWindow(rtv->window) : 0;
	rtv->buf ? free_char_arr(rtv->buf) : 0;
	rtv->objs ? objs_free(rtv->objs) : 0;
	rtv->light ? light_free(rtv->light) : 0;
	SDL_Quit();
}

void	exit_with_message(char *message, int std_error, t_rtv *rtv)
{
	std_error ? perror(message) : ft_putendl(message);
	free_rtv(rtv);
	exit(-1);
}

#include "../include/rtv1.h"

static void	rotate_cam(t_rtv *rtv, const uint8_t *keys)
{
	if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT])
	{
		rtv->cam.dir.y = keys[SDL_SCANCODE_LEFT] ?\
		rtv->cam.dir.y - 0.5 : rtv->cam.dir.y + 0.5;
	}
	if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_DOWN])
	{
		rtv->cam.dir.x = keys[SDL_SCANCODE_UP] ?\
		rtv->cam.dir.x - 0.5 : rtv->cam.dir.x + 0.5;
	}
	ray(rtv);
}

int			rtv_loop(t_rtv *rtv)
{
	const uint8_t	*keys;
	SDL_Event		event;

	keys = SDL_GetKeyboardState(NULL);
	while (rtv->run)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN
			&& event.key.keysym.sym == SDLK_ESCAPE))
		{
			rtv->run = 0;
			break ;
		}
		if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT] ||\
			keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_DOWN])
			rotate_cam(rtv, keys);
	}
	return (0);
}

#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define RAY_MAX 2147483647.0
# define RAY_MIN 0.001
# define SHADOW_MIN 0.001
# define FOR_RAY 0
# define FOR_SHADOW 1
# define SPHERE 1
# define PLANE 2
# define CONE 3
# define CYLINDER 4

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_cam
{
	t_vec			pos;
	t_vec			dir;
}					t_cam;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_obj
{
	int				type;
	double			size;
	t_vec			pos;
	t_vec			rot;
	t_color			col;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_light
{
	t_vec			pos;
	int				intens;
	struct s_light	*next;
}					t_light;

typedef struct		s_intesection
{
	t_vec			pos_vec;
	t_vec			dir_vec;
	double			min;
	double			max;
}					t_intersection;

typedef struct		s_rtv
{
	t_cam			cam;
	t_obj			*objs;
	t_light			*light;
	char			**buf;
	char			*config_file_path;
	SDL_Window		*window;
	SDL_Surface		*surface;
	int				run;
	t_vec			d;
	t_intersection	inter;
	double			ambient;
}					t_rtv;

void				exit_with_message(char *message, int std_error, t_rtv *rtv);
void				free_rtv(t_rtv *rtv);
void				check_input(int argc, char **argv, t_rtv *rtv);
void				init_sdl(t_rtv *rtv);
void				init_struct_rtv(t_rtv *rtv, char *path);
void				init_rtv(t_rtv *rtv);
int					rtv_loop(t_rtv *rtv);
void				sphere_intersection
		(t_rtv *rtv, t_obj *sphere, t_obj **closest_obj, double *closest_t);
void				plane_intersection
		(t_rtv *rtv, t_obj *plane, t_obj **closest_obj, double *closest_t);
void				cyl_intersection
		(t_rtv *rtv, t_obj *cyl, t_obj **closest_obj, double *closest_t);
void				cone_intersection
		(t_rtv *rtv, t_obj *cone, t_obj **closest_obj, double *closest_t);
void				read_input_file(t_rtv *rtv);
void				get_sphere(t_rtv *rtv);
void				get_cone(t_rtv *rtv);
void				get_cyl(t_rtv *rtv);
void				get_plane(t_rtv *rtv);
void				get_camera(t_rtv *rtv);
void				get_light(t_rtv *rtv);
void				get_ambient_light(t_rtv *rtv);
void				record_line_info(t_rtv *rtv);
void				read_input_file(t_rtv *rtv);
t_vec				record_vec_from_str(char *str, t_rtv *rtv);
t_color				record_color_from_str(char *str, t_rtv *rtv);
char				**free_char_arr(char **arr);
int					arr_len(char **arr);
t_obj				*new_obj(t_obj *curr);
void				objs_free(t_obj *l);
t_light				*new_light(t_light *curr);
void				light_free(t_light *l);
void				ray(t_rtv *rtv);
t_vec				sub_vec(t_vec a, t_vec b);
double				scal_mult_vec(t_vec a, t_vec b);
t_vec				norm_vec(t_vec a);
t_vec				rotate_vec(t_vec angle, t_vec a);
t_vec				mult_vec_num(t_vec a, double num);
double				len_vec(t_vec a);
t_vec				div_vec_num(t_vec a, double num);
t_vec				calculate_normal
		(t_rtv *rtv, t_obj *closest_obj, t_vec inter_point, double closest_t);
t_vec				sum_vec(t_vec a, t_vec b);
t_vec				minus_num_vec(t_vec a, t_vec b);
t_vec				mult_by_num(t_vec a, double b);
void				init_intesection_struct
		(t_rtv *rtv, int purpose, t_vec pos, t_vec dir);

#endif

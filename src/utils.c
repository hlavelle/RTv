#include "../include/rtv1.h"

t_vec		record_vec_from_str(char *str, t_rtv *rtv)
{
	char	**buf_elem;
	t_vec	vec;

	buf_elem = ft_strsplit(str, ',');
	if (arr_len(buf_elem) != 3)
	{
		buf_elem = free_char_arr(buf_elem);
		exit_with_message("Invalid vector info", 0, rtv);
	}
	vec.x = (double)ft_atoi(buf_elem[0]);
	vec.y = (double)ft_atoi(buf_elem[1]);
	vec.z = (double)ft_atoi(buf_elem[2]);
	buf_elem = free_char_arr(buf_elem);
	return (vec);
}

static void	free_arr_and_exit(char **arr, char *message, t_rtv *rtv)
{
	arr = free_char_arr(arr);
	exit_with_message(message, 0, rtv);
}

t_color		record_color_from_str(char *str, t_rtv *rtv)
{
	char	**buf_elem;
	t_color	col;

	buf_elem = ft_strsplit(str, ',');
	if (arr_len(buf_elem) != 3)
		free_arr_and_exit(buf_elem, "Invalid color info", rtv);
	col.r = ft_atoi(buf_elem[0]);
	if (col.r > 255 || col.r < 0)
		free_arr_and_exit(buf_elem, "Invalid color info", rtv);
	col.g = ft_atoi(buf_elem[1]);
	if (col.g > 255 || col.g < 0)
		free_arr_and_exit(buf_elem, "Invalid color info", rtv);
	col.b = ft_atoi(buf_elem[2]);
	if (col.b > 255 || col.b < 0)
		free_arr_and_exit(buf_elem, "Invalid color info", rtv);
	buf_elem = free_char_arr(buf_elem);
	return (col);
}

char		**free_char_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr && arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
	return (arr);
}

int			arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

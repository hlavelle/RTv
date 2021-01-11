#include "../include/rtv1.h"

void	check_input(int argc, char **argv, t_rtv *rtv)
{
	int fd;

	init_struct_rtv(rtv, argv[1]);
	if (argc != 2)
		exit_with_message("usage: ./RTv1 file_path", 0, rtv);
	else if (WIN_HEIGHT != WIN_WIDTH)
		exit_with_message("Width != Height", 0, rtv);
	else
	{
		if ((fd = open(argv[1], O_DIRECTORY)) >= 0 ||
			(fd = open(argv[1], O_RDONLY)) < 0)
			exit_with_message("RTv1", 1, rtv);
		close(fd);
	}
}

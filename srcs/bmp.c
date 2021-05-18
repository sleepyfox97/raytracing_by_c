#include "./miniRT.h"

static void	wirte_bmp_file_header(t_minirt *rt, int fd)
{
	uint32_t	filesize;
	uint32_t	offset;

	write(fd, "BM", 2);
	filesize = 14 + 10 + rt->width * rt->hight * 4;
	write(fd, &filesize, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	offset = 14 + 10;
	write(fd, &offset, 4);
}

static void	write_bmp_info_header(t_minirt *rt, int fd)
{
	uint32_t	tmp;

	tmp = 12;
	write(fd, &tmp, 4);
	tmp = (uint32_t)(rt->width);
	write(fd, &tmp, 2);
	tmp = (uint32_t)(rt->hight);
	write(fd, &tmp, 2);
	tmp = 1;
	write(fd, &tmp, 2);
	tmp = 32;
	write(fd, &tmp, 2);
}

static void	write_image_data(t_minirt *rt, int *image, int fd)
{
	unsigned int	tmp;
	int				x;
	int				y;

	y = rt->hight - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < rt->width)
		{
			tmp = (unsigned int)image[y + x * (int)rt->hight];
			write(fd, &tmp, 4);
			x++;
		}
		y--;
	}
}

void	ft_null_camera_error(void)
{
	ft_put_camera_error();
	exit (0);
}

int	make_bmpfile(t_minirt *rt)
{
	int		fd;
	int		tmp;
	char	file[7];

	if (rt->firstcam == NULL)
		ft_null_camera_error();
	tmp = rt->firstcam->cnum;
	ft_memcpy(file, "./a.bmp", 7);
	while (1)
	{
		fd = open(file, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
		if (fd == -1)
			return (0);
		wirte_bmp_file_header(rt, fd);
		write_bmp_info_header(rt, fd);
		write_image_data(rt, rt->firstcam->image, fd);
		close(fd);
		rt->firstcam =rt->firstcam->next;
		if (rt->firstcam->cnum == tmp)
			break ;
		file[2] = file[2] + 1;
	}
	return (1);
}

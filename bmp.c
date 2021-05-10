#include "./miniRT.h"

//bmpファイルは左下から，右上に向かって表示される．
//画像の横データは4の倍数にbyteに揃えないと行けない．そろわない部分には0を入れる
//今回は，一ピクセル24bitの3bytemapなので，ここに注意
//filesize=14 + 10の部分の14はheader部分，10は
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

//information headerのsize
//プレーン数，常に1で2byte

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

//imageはRGBの並びなので，BRGの並びにして，0が一番下の8btiを占めるようにbitシフトして返す．
static unsigned int	get_image(int *image, int x, int y, t_minirt *rt)
{
	unsigned int	re;

	re = (unsigned int)image[y + x * (int)rt->hight];
	return (re);
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
			tmp = get_image(image, x, y, rt);
			write(fd, &tmp, 4);
			x++;
		}
		y--;
	}
}

//カメラごとに適当に名前を付ける必要がある．
int	make_bmpfile(t_minirt *rt)
{
	int		fd;
	int		tmp;
	char	file[7];

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
		file[2] = 'a' + 1;
	}
	return (1);
}

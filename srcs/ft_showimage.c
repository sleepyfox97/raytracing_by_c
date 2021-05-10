#include "./miniRT.h"

void	ft_show_image(t_minirt *rt, int *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < rt->width)
	{
		j = 0;
		while (j < rt->hight)
		{
			mlx_pixel_put(rt->mlx, rt->win, i, j, c[i * (int)rt->hight + j]);
			j++;
		}
		i++;
	}
	return ;
}

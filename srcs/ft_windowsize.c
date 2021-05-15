#include "./miniRT.h"

void	ft_window_resize(t_minirt *minirt)
{
	int	w;
	int	h;

	mlx_get_screen_size(minirt->mlx, &w, &h);
	if (w < (int)minirt->width)
		minirt->width = (double)w;
	if (h < (int)minirt->hight)
		minirt->hight = (double)h;
	return ;
}

#include "./miniRT.h"


//int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

int		ft_kye_evet(int kyecode, t_minirt *minirt)
{
	if (kyecode == K_ESC)
		ft_close(kyecode, minitr);
	if (kyecode == K_LEFT)
		ft_change_camera_next(kyecode, minirt);
	if (Kyecode == K_RIGHT)
		ft_change_camera_prev(kyecode, minirt);
}

void	ft_close(int keycode, t_minirt *minirt)
{
	mlx_destroy_window(minirt->mlx, minirt->win);
	exit(0);
	return ;
}

void	ft_window_resize(int keycode, t_minirt *minirt)
{
	int w;
	int h;

	mlx_get_screen_size(minirt->mlx_ptr, &w, &h);//error返ってくる？
	if (w < minirt->width)
		minirt->width = w;
	if (h < minirt->hight)
		minirt->hight = h;
	return ;
}

void	ft_change_camera_next(int kyecode, t_minirt *minirt)
{

}

void	ft_change_camera_prev(int kyecode, t_minirt *minirt)
{

}

#include "./miniRT.h"

int	ft_key_event(int kyecode, t_minirt *rt)
{
	if (kyecode == K_ESC)
		ft_close(kyecode, rt);
	if (kyecode == K_LEFT)
		ft_change_camera_next(kyecode, rt);
	if (kyecode == K_RIGHT)
		ft_change_camera_prev(kyecode, rt);
	return (0);
}

void	ft_change_camera_next(int kyecode, t_minirt *rt)
{
	rt->firstcam = rt->firstcam->next;
	ft_use_mlx(rt);
	return ;
}

void	ft_change_camera_prev(int kyecode, t_minirt *rt)
{
	rt->firstcam = rt->firstcam->prev;
	ft_use_mlx(rt);
	return ;
}

//free everything?
void	ft_close(int keycode, t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
	return ;
}

//clickでwindow閉じるときの関数
//clickで終了するとなぜかsegfoが起こる．escpだとおこらない．
//free everything?
int	ft_click_event(int keycode, t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
	return (0);
}

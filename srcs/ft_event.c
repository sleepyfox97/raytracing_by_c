#include "./miniRT.h"

int	ft_key_event(int kyecode, t_minirt *rt)
{
	if (kyecode == K_ESC)
		ft_close(rt);
	if (kyecode == K_LEFT)
		ft_change_camera_next(rt);
	if (kyecode == K_RIGHT)
		ft_change_camera_prev(rt);
	return (0);
}

void	ft_change_camera_next(t_minirt *rt)
{
	rt->firstcam = rt->firstcam->next;
	ft_use_mlx(rt);
	return ;
}

void	ft_change_camera_prev(t_minirt *rt)
{
	rt->firstcam = rt->firstcam->prev;
	mlx_clear_window(rt->mlx, rt->win);
	ft_use_mlx(rt);
	return ;
}

//free everything?
void	ft_close(t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_clear_window(rt->mlx, rt->win);
	exit(0);
	return ;
}

//clickでwindow閉じるときの関数
//clickで終了するとなぜかsegfoが起こる．escpだとおこらない．
//free everything?
int	ft_click_event(t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
	return (0);
}
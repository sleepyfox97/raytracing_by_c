#include "./miniRT.h"

//1L<<0はshift maskって意味っぽい
void	ft_use_mlx(t_minirt *rt)
{
	ft_show_image(rt, rt->firstcam->image);
	mlx_hook(rt->win, 2, 1L << 0, ft_key_event, rt);
	mlx_hook(rt->win, 33, 1L << 17, ft_click_event, rt);
	mlx_hook(rt->win, 19, 1L << 17, ft_show_event, rt);
	mlx_loop(rt->mlx);
	return ;
}

int	ft_show_event(t_minirt *rt)
{
	ft_show_image(rt, rt->firstcam->image);
	return (1);
}

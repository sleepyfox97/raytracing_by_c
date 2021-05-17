#include "./miniRT.h"

int	ft_key_event(int kyecode, t_minirt *rt)
{
	if (rt->firstcam != NULL)
	{
		if (kyecode == K_LEFT)
			ft_change_camera_next(rt);
		if (kyecode == K_RIGHT)
			ft_change_camera_prev(rt);
	}
	if (kyecode == K_ESC)
		ft_close(rt);
	return (0);
}

void	ft_change_camera_next(t_minirt *rt)
{
	rt->firstcam = rt->firstcam->next;
	printf("\n\x1b[35m===NOW===\033[m\n");
	printf("camera place \n");
	ft_put_vector(rt->firstcam->p);
	printf("\nnormalized orientation vector of camera\n");
	ft_put_vector(rt->firstcam->vd);
	printf("\ncamera's fov = %lf\n", rt->firstcam->fov);
	ft_use_mlx(rt);
	return ;
}

void	ft_change_camera_prev(t_minirt *rt)
{
	rt->firstcam = rt->firstcam->prev;
	printf("\n\x1b[35m===NOW===\033[m\n");
	printf("camera place \n");
	ft_put_vector(rt->firstcam->p);
	printf("\nnormalized orientation vector of camera\n");
	ft_put_vector(rt->firstcam->vd);
	printf("\ncamera's fov = %lf\n", rt->firstcam->fov);
	ft_use_mlx(rt);
	return ;
}

void	ft_close(t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_clear_window(rt->mlx, rt->win);
	exit(0);
	return ;
}

int	ft_click_event(t_minirt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
	return (0);
}

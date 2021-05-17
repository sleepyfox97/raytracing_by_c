#include "./miniRT.h"

int	ft_prepare_print(t_minirt *rt)
{
	if (!ft_cam_prepare(rt->firstcam, rt->width, rt->hight))
		return (0);
	ft_obj_prepare(rt->firstgob);
	return (1);
}

void	ft_light_prepare(t_light *flight, t_cam *cam)
{
	t_light	*tmp1;
	int		i;

	tmp1 = flight;
	i = 1;
	while (flight != NULL)
	{
		flight->lnum = i;
		flight->vctol = ft_linear_transform(flight->p, cam->p, 1, -1);
		i++;
		flight = flight->next;
	}
	flight = tmp1;
	return ;
}

int	ft_cam_prepare(t_cam *firstcam, double width, double hight)
{
	t_cam	*tmp1;
	t_cam	*tmp2;
	int		i;

	tmp1 = firstcam;
	i = 1;
	while (firstcam != NULL)
	{
		firstcam->fov = firstcam->fov * M_PI / 180;
		firstcam->vptos = ft_linear_transform(firstcam->vd,
				firstcam->vd, (width / (2 * (tan(firstcam->fov / 2)))), 0);
		firstcam = ft_make_screan_base(firstcam);
		firstcam->cnum = i;
		firstcam->image = (int *)malloc(sizeof(int) * width * hight);
		if (firstcam->image == NULL)
			return (0);
		if (firstcam->next == NULL)
			tmp2 = firstcam;
		firstcam = firstcam->next;
		i++;
	}
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	return (1);
}


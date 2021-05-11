#include "./miniRT.h"

//minirt->firstgob = tmpの部分が無くてもいいかも
void	ft_print_obj(t_minirt *rt)
{
	int		i;
	double	x;
	t_gob	*tmp;

	tmp = rt->firstgob;
	while (1)
	{
		if (isin_sphere(rt->firstcam, rt->firstgob))
			ft_set_black(rt->firstcam->image, rt->width, rt->hight);
		else
		{
			i = 0;
			ft_light_prepare(rt->firstlight, rt->firstcam);
			while (i < (int)rt->width)
			{
				x = i - rt->width / 2;
				ft_print_objsub(rt, x, i, tmp);
				ft_progress(rt, i, rt->firstcam);
				i++;
			}
		}
		if (rt->firstcam->next->cnum == 1)
			break ;
		rt->firstcam = rt->firstcam->next;
	}
}

void	ft_print_objsub(t_minirt *rt, double x, int i, t_gob *first)
{
	double	y;
	int		j;

	j = 0;
	while (j < (int)rt->hight)
	{
		y = (-1) * (j - rt->hight / 2);
		rt->firstgob = first;
		rt->firstcam->image[i * (int)rt->hight + j]
			= ft_calcu_color(rt, x, y);
		j++;
	}
}

int	ft_calcu_color(t_minirt *rt, double x, double y)
{
	int		color;
	t_color	c;

	rt->firstcam->distance = INFINITY;
	rt->firstcam->vray = ft_make_ray(rt->firstcam, x, y);
	rt->firstcam->tmpcolor = ft_set_color(0, 0, 0);
	while (1)
	{
		if (rt->firstgob->type == 1)
			ft_sp_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 2)
			ft_pl_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 3)
			ft_sq_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 4)
			ft_cy_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 5)
			ft_tr_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		if (rt->firstgob->next->obnum == 1)
			break ;
		rt->firstgob = rt->firstgob->next;
	}
	c = rt->firstcam->tmpcolor;
	color = (int)c.r << 16 | (int)c.g << 8 | (int)c.b;
	return (color);
}

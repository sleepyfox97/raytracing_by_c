#include "./miniRT.h"

double	ft_sq_color(t_gob *sq, t_cam *cam, t_light *l, t_amblight al)
{
	double	t;
	t_light	*ltmp;

	t = ft_make_sq(sq, cam->vray, cam->p);
	if (cam->distance > t && t >0)
	{
		cam->distance = t;
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al, sq->color);
		ltmp = l;
		while (l != NULL)
		{
			if (!ft_iscross(sq, l, cam))
				ft_diffusion_light_pl(cam, l, sq);
			l = l->next;
		}
		l = ltmp;
	}
	return (cam->distance);
}

//like make screan, make two base vector. sq->d is half of length
double	ft_make_sq(t_gob *sq, t_vec3 vray, t_vec3 camp)
{
	t_vec3	tmp1;
	t_vec3	tmp2;
	double	distance;
	double	a;
	double	b;

	distance = ft_make_pl(sq, vray, camp);
	if (distance <= 0 || distance == INFINITY)
		return (INFINITY);
	tmp1 = ft_linear_transform(vray, camp, distance, 1);
	tmp2 = ft_linear_transform(tmp1, sq->p1, 1, -1);
	a = ft_inner_product(tmp2, sq->p2);
	if (a < (-1) * sq->d || sq->d < a)
		return (INFINITY);
	b = ft_inner_product(tmp2, sq->p3);
	if (b < (-1) * sq->d || sq->d < b)
		return (INFINITY);
	return (distance);
}

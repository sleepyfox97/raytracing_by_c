#include "./miniRT.h"

double	ft_tr_color(t_gob *tr, t_cam *cam, t_light *l, t_amblight al)
{
	double	t;
	t_light	*ltmp;

	t = ft_make_tr(tr, cam->vray, cam->p);
	if (cam->distance > t && t > 0)
	{
		cam->distance = t;
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al);
		ltmp = l;
		while (l != NULL)
		{
			if (!ft_iscross(tr, l, cam))
				ft_diffusion_light_pl(cam, l, tr);
			l = l->next;
		}
		l = ltmp;
	}
	return (cam->distance);
}

//tmp1 is place of reflect point, so can out of while.
double	ft_make_tr(t_gob *tr, t_vec3 vray, t_vec3 camp)
{
	double	distance;
	double	a;
	double	b;
	t_vec3	tmp1;
	t_vec3	tmp2;

	distance = ft_make_pl(tr, vray, camp);
	if (distance <= 0 || distance == INFINITY)
		return (INFINITY);
	tmp1 = ft_linear_transform(vray, camp, distance, 1);
	tmp2 = ft_make_unitvec(ft_linear_transform(tmp1, tr->p1, 1, -1));
	a = ft_inner_product(tmp2, tr->vtb1);
	b = ft_inner_product(tmp2, tr->vtb2);
	if ((tr->d <= a && a <= 1) && (tr->d <= b && b <= 1))
	{
		tmp2 = ft_make_unitvec(ft_linear_transform(tmp1, tr->p2, 1, -1));
		a = ft_inner_product(tmp2, tr->vtb3);
		b = ft_inner_product(tmp2, tr->vctoc);
		if ((tr->h <= a && a <= 1) && (tr->h <= b && b <= 1))
			return (distance);
	}
	return (INFINITY);
}

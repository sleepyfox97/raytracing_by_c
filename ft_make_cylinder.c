#include "./miniRT.h"

double	ft_cy_color(t_gob *cy, t_cam *cam, t_light *l, t_amblight al)
{
	double	t;
	t_light	*ltmp;

	t = ft_make_cy(cy, cam->vray, cam->p);
	if (cam->distance > t && t > 0)
	{
		cam->distance = t;
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al);
		ltmp = l;
		while (l != NULL)
		{
			if (!ft_iscross(cy, l, cam))
				ft_diffusion_light_cy(cam, l, cy);
			l = l->next;
		}
		l = ltmp;
	}
	return (cam->distance);
}

//always -1 <= a <= 1
//calcu cy->vctoc can throw out of while
double	ft_make_cy(t_gob *cy, t_vec3 vray, t_vec3 camp)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = ft_inner_product(vray, cy->vno);
	if (a == 1 || a == -1)
		return (INFINITY);
	cy->vctoc = ft_linear_transform(camp, cy->p1, 1, -1);
	c = ft_inner_product(cy->vctoc, cy->vno);
	b = ft_inner_product(vray, cy->vctoc) - c * a;
	c = ft_v_d_len(cy->vctoc) - c * c - cy->d * cy->d / 4;
	d = ft_make_cy_sub(a, b, c, cy);
	return (d);
}

double	ft_make_cy_sub(double a, double b, double c, t_gob *cy)
{
	double	tmp;
	double	d;
	double	t;

	tmp = (1 - a * a);
	d = b * b - c * tmp;
	if (d < 0 || tmp == 0)
		return (INFINITY);
	t = ft_quadratic_func(tmp, b, c);
	if (0 < t && t < INFINITY)
	{
		cy->p2.y = t * a + ft_inner_product(cy->vctoc, cy->vno);
		cy->p2.x = 1;
		if (0 <= cy->p2.y && cy->p2.y <= cy->h)
			return (t);
		else if (c >= 0)
		{
			t = t + 2 * sqrt(d) / tmp;
			cy->p2.y = t * a + ft_inner_product(cy->vctoc, cy->vno);
			cy->p2.x = 2;
			if (0 <= cy->p2.y && cy->p2.y <= cy->h)
				return (t);
		}
	}
	return (INFINITY);
}

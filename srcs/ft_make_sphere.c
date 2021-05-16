#include "./miniRT.h"

////calcu cy->vctoc can throw out of while
double	ft_sp_color(t_gob *sp, t_cam *cam, t_light *l, t_amblight al)
{
	double	tmp1;
	t_light	*tmp2;

	sp->vctoc = ft_linear_transform(sp->p1, cam->p, -1, 1);
	tmp2 = l;
	tmp1 = ft_make_sp(cam, sp);
	if (cam->distance > tmp1)
	{
		cam->distance = tmp1;
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al, sp->color);
		while (l != NULL)
		{
			if (!ft_iscross(sp, l, cam))
				ft_diffusion_light_sp(cam, l, sp, sp->vctoc);
			l = l->next;
		}
	}
	l = tmp2;
	return (cam->distance);
}

//if argument change cam to vray, can use iscross func
//size of vray is allways 1, so a == 1;
//c dosen't change so, can throw out of while.
double	ft_make_sp(t_cam *cam, t_gob *sp)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = 1;
	b = ft_inner_product(cam->vray, sp->vctoc);
	c = ft_v_d_len(sp->vctoc) - sp->d * sp->d / 4;
	t = ft_quadratic_func(a, b, c);
	return (t);
}

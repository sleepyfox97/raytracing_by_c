#include "./miniRT.h"

//cy->p2.yの値が，lightによって書き換わっていてのが問題．
void	ft_diffusion_light_cy(t_cam *cam, t_light *l, t_gob *cy, t_vec3 vncp)
{
	double	cos1;
	double	cos2;
	t_vec3	p;
	t_vec3	v1;

	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1.0);
	if (cy->p2.x == 1)
		vncp = ft_make_unitvec(ft_linear_transform(p, vncp, 1, -1));
	else
		vncp = ft_make_unitvec(ft_linear_transform(vncp, p, 1, -1));
	v1 = ft_make_unitvec(ft_linear_transform(l->p, p, 1, -1));
	cos1 = ft_inner_product(vncp, v1);
	if (cos1 > 0 && !iscycross(cy, l->p, p))
		cam->tmpcolor = ft_set_d_color
			(cam->tmpcolor, l->color, cy->color, cos1 * l->r);
	else
		return ;
	p = ft_make_unitvec(ft_linear_transform(v1, vncp, (-2) * cos1, 1));
	cos2 = ft_inner_product(cam->vray, p);
	if (cos2 > 0)
		ft_diffusion_light_cysub(cos2, cam, l, cy);
	return ;
}

void	ft_diffusion_light_cysub(double cos2, t_cam *c, t_light *l, t_gob *cy)
{
	cos2 = pow(cos2, 10) * l->r * 0.6;
	c->tmpcolor = ft_set_d_color(c->tmpcolor, l->color, cy->color, cos2);
}

int	iscycross(t_gob *cy, t_vec3 lp, t_vec3 p)
{
	t_vec3	tmp;
	double	l;
	double	t;
	double	a;

	if (cy->p2.x == 1)
		return (0);
	a = cy->p2.x;
	tmp = ft_linear_transform(lp, p, -1, 1);
	l = sqrt(ft_v_d_len(tmp));
	tmp = ft_make_unitvec(tmp);
	t = ft_make_cy(cy, tmp, lp);
	cy->p2.x = a;
	if (0.000000001 < t && t < l - 0.000000001)
		return (1);
	return (0);
}

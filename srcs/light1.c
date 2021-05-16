#include "./miniRT.h"

//difuselightと同様にうまく掛け算する必要がある．
t_color	ft_ambient_light(t_color c_color, t_amblight a, t_color o_color)
{
	c_color.r = a.color.r * a.r * o_color.r / 255;
	c_color.g = a.color.g * a.r * o_color.g / 255;
	c_color.b = a.color.b * a.r * o_color.b / 255;
	return (c_color);
}

//t_vec3 v is sp.p1 to cam.p
//v1:normal vector at reflecting point.
//v2:vector form reflecting point to light
void 	ft_diffusion_light_sp(t_cam *c, t_light *l, t_gob *sp, t_vec3 v)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	double	cos1;
	double	cos2;

	v1 = ft_linear_transform(c->vray, v, c->distance, 1);
	v1 = ft_make_unitvec(v1);
	v2 = ft_linear_transform(c->vray, l->vctol, (-1) * c->distance, 1);
	v2 = ft_make_unitvec(v2);
	cos1 = ft_inner_product(v1, v2);
	if (cos1 > 0)
		c->tmpcolor = ft_set_d_color
			(c->tmpcolor, l->color, sp->color, cos1 * l->r);
	v3 = ft_linear_transform(v1, v2, (-2) * cos1, 1);
	v3 = ft_make_unitvec(v3);
	cos2 = ft_inner_product(c->vray, v3);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 1;
		c->tmpcolor = ft_set_d_color(c->tmpcolor, l->color, sp->color, cos2);
	}
	return ;
}

//you havet to check direction of normal vector
void	ft_diffusion_light_pl(t_cam *c, t_light *l, t_gob *pl)
{
	double	cos1;
	double	cos2;
	double	tmp;
	t_vec3	v1;
	t_vec3	p;

	p = ft_linear_transform(c->vray, c->p, c->distance, 1);
	tmp = ft_inner_product(ft_linear_transform(c->p, p, 1, -1), pl->vno);
	if (tmp < 0)
		pl->vno = ft_linear_transform(pl->vno, pl->vno, -1, 0);
	v1 = ft_linear_transform(l->p, p, 1, -1);
	v1 = ft_make_unitvec(v1);
	cos1 = ft_inner_product(pl->vno, v1);
	if (cos1 > 0)
		c->tmpcolor = ft_set_d_color
			(c->tmpcolor, l->color, pl->color, cos1 * l->r);
	p = ft_linear_transform(v1, pl->vno, 1, (-2) * cos1);
	p = ft_make_unitvec(p);
	cos2 = ft_inner_product(c->vray, p);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 0.5;
		c->tmpcolor = ft_set_d_color(c->tmpcolor, l->color, pl->color, cos2);
	}
	return ;
}

t_color	ft_set_d_color(t_color c_c, t_color l_c, t_color s_c, double cos)
{
	t_color	rgb;

	rgb.r = (s_c.r / 255) * (l_c.r / 255) * cos * 255;
	rgb.g = (s_c.g / 255) * (l_c.g / 255) * cos * 255;
	rgb.b = (s_c.b / 255) * (l_c.b / 255) * cos * 255;
	c_c.r = rgb.r + c_c.r;
	if (c_c.r > 255)
		c_c.r = 255;
	c_c.g = rgb.g + c_c.g;
	if (c_c.g > 255)
		c_c.g = 255;
	c_c.b = rgb.b + c_c.b;
	if (c_c.b > 255)
		c_c.b = 255;
	return (c_c);
}

t_color	ft_set_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

//this function change light reflection
// t_color	ft_set_diffuse_color1
// (t_color c_c, t_color l_c, t_color s_c, double cos)
// {
// 	t_color rgb;

// 	rgb.r = (s_c.r / 255) * (l_c.r / 255) * cos * 255;
// 	rgb.g = (s_c.g / 255) * (l_c.g / 255) * cos * 255;
// 	rgb.b = (s_c.b / 255) * (l_c.b / 255) * cos * 255;
// 	if (rgb.r > 255)
// 		rgb.r = 255;
// 	if (rgb.g > 255)
// 		rgb.g = 255;
// 	if (rgb.b > 255)
// 		rgb.b = 255;
// 	if (rgb.r > c_c.r)
// 		c_c.r = rgb.r;
// 	if (rgb.g > c_c.g)
// 		c_c.g = rgb.g;
// 	if (rgb.b > c_c.b)
// 		c_c.b = rgb.b;
// 	return (c_c);
// }

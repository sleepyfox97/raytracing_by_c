#include "./miniRT.h"

t_cam	*ft_make_screan_base(t_cam *cam)
{
	// if (cam->vd.x == 0 && cam->vd.y >= 0)
	// 	cam->vsb1 = ft_set_vecele(1, 0, 0);
	// else if (cam->vd.x == 0 && cam->vd.y < 0)
	// 	cam->vsb1 = ft_set_vecele(-1, 0, 0);
	// else if (cam->vd.y == 0 && cam->vd.x >= 0)
	// 	cam->vsb1 = ft_set_vecele(0, -1 , 0);
	// else if (cam->vd.y == 0 && cam->vd.x < 0)
	// 	cam->vsb1 = ft_set_vecele(0, 1 , 0);
	// else
	// {
	// 	cam->vsb1.x = 1;
	// 	cam->vsb1.z = 0;
	// 	cam->vsb1.y = (-1) * (cam->vd.x * cam->vsb1.x) / cam->vd.y;
	// }
	// if (cam->vd.z == 0)
	// 	cam->vsb2 = ft_set_vecele(0,0,1);
	// else
	// 	cam->vsb2 = ft_cross_product(cam->vsb1, cam->vd);
	// cam->vsb1 = ft_make_unitvec(cam->vsb1);
	// cam->vsb2 = ft_make_unitvec(cam->vsb2);
	cam->vsb1 = make_screan_util1(cam->vd);
	cam->vsb2 = make_screan_util2(cam->vd, cam->vsb1);
	return (cam);
}

t_vec3	make_screan_util2(t_vec3 vd, t_vec3 vsb1)
{
	t_vec3 vsb2;

	if (vd.z == 0)
		vsb2 = ft_set_vecele(0,0,1);
	else
		vsb2 = ft_cross_product(vsb1, vd);
	vsb2 = ft_make_unitvec(vsb2);
	return (vsb2);
}

t_vec3	make_screan_util1(t_vec3 vd)
{
	t_vec3	vsb1;

	if (vd.x == 0 && vd.y >= 0)
		vsb1 = ft_set_vecele(1, 0, 0);
	else if (vd.x == 0 && vd.y < 0)
		vsb1 = ft_set_vecele(-1, 0, 0);
	else if (vd.y == 0 && vd.x >= 0)
		vsb1 = ft_set_vecele(0, -1 , 0);
	else if (vd.y == 0 && vd.x < 0)
		vsb1 = ft_set_vecele(0, 1 , 0);
	else
	{
		vsb1.x = 1;
		vsb1.z = 0;
		vsb1.y = (-1) * (vd.x * vsb1.x) / vd.y;
	}
	vsb1 = ft_make_unitvec(vsb1);
	return (vsb1);
}

//nor対応とbonusのカメラ回転を考えて，各ピクセルについて回している部分は別関数に投げるのが良さげ．
//引数として，h(hight)とw(width)を用意して投げる．



//必ず，正の方向の値として，長さを取りたいときに使う．a正を保証して用いる．
double	ft_quadratic_func(double a, double b, double c)
{
	double	d;

	d = b * b - a * c;
	if (d > 0)
	{
		// if (a > 0)
		// {
			if ((-1) * b - sqrt(d) > 0)
				return (((-1) * b - sqrt(d)) / a);
			else if ((-1) * b + sqrt(d) <= 0)
				return (INFINITY);
			else
				return (((-1) * b + sqrt(d)) / a);
		// }
	// 	else if (a < 0)//怪しい
	// 	{
	// 		if ((-1) * b + sqrt(d) < 0)
	// 			return (((-1) * b + sqrt(d)) / a);
	// 		else if ((-1) * b - sqrt(d) >= 0)
	// 			return (INFINITY);
	// 		else
	// 			return (((-1) * b - sqrt(d)) / a);
	// 	}
	// 	else
	// 		return (INFINITY);
	}
	else
		return (INFINITY);
}

// t_color	ft_set_diffuse_color1(t_color c_c, t_color l_c, t_color s_c, double cos)
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

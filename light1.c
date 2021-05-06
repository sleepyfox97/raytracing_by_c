#include "./miniRT.h"

t_color	ft_ambient_light(t_color c_color, t_amblight a)
{
	c_color.r = a.color.r * a.r;
	c_color.g = a.color.g * a.r;
	c_color.b = a.color.b * a.r;
	return (c_color);
}
	//拡散，鏡面，環境を足すのが一番それっぽくなる気がする．
	//ここら辺上手に考えたら計算量減らせそう．
	//vは球の中心んからカメラへ向かうベクトルになってる
void 	ft_diffusion_light_sp(t_cam *cam, t_light *l, t_gob *sp, t_vec3 v)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	double	cos1;
	double	cos2;

	v1 = ft_linear_transform(cam->vray, v, cam->distance, 1);//拡散点における法線ベクトル
	v1 = ft_make_unitvec(v1);
	v2 = ft_linear_transform(cam->vray, l->vctol, (-1) * cam->distance, 1);//拡散点からlightに向かう
	v2 = ft_make_unitvec(v2);
	cos1 = ft_inner_product(v1, v2);
	if (cos1 > 0)
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, sp->color, cos1 * l->r);
	v3 = ft_linear_transform(v1, v2, (-2) * cos1, 1);//向きに注意
	v3 = ft_make_unitvec(v3);
	cos2 = ft_inner_product(cam->vray, v3);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 0.6;//正の時に2乗しないとダメ．
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, sp->color, cos2);
	}
	return ;
}

//sqareとtriangleに活用可能．
void	ft_diffusion_light_pl(t_cam *cam, t_light *l, t_gob *pl)
{
	double	cos1;
	double	cos2;
	double	tmp;
	t_vec3	v1;
	t_vec3	p;

	//もし，vnoの方向がカメラの存在する側に向かうベクトルじゃなかったらいい感じに書き換える．平面の方程式にカメラ座標代入して，正負見る．
	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	tmp = ft_inner_product(ft_linear_transform(cam->p, p, 1, -1), pl->vno);
	if (tmp < 0)
		pl->vno = ft_linear_transform(pl->vno, pl->vno, -1, 0);
	v1 = ft_linear_transform(l->p, p, 1, -1);
	v1 = ft_make_unitvec(v1);
	cos1 = ft_inner_product(pl->vno, v1);
	if (cos1 > 0)
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, pl->color, cos1 * l->r);
	p = ft_linear_transform(v1, pl->vno, 1, (-2) * cos1);
	p = ft_make_unitvec(p);
	cos2 = ft_inner_product(cam->vray, p);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 0.5;//
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, pl->color, cos2);
	}
	return ;
}


t_color	ft_set_diffuse_color2(t_color c_c, t_color l_c, t_color s_c, double cos)
{
	t_color rgb;

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

t_color ft_set_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

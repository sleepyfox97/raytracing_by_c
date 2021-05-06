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

//yの範囲ないになかった時に，もう一方の解が採用できるかの場合分けが必要になる．
//計算量がダメダメなので，多分もう少し上手に最適化できるはず．
double	ft_make_cy(t_gob *cy, t_vec3 vray, t_vec3 camp)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = ft_inner_product(vray, cy->vno);//正負問題が生じる．->1 - a ^ 2は常に正
	if (a == 1 || a == -1)
		return (INFINITY);
	cy->vctoc = ft_linear_transform(camp, cy->p1, 1, -1);//計算量減らしたかったら，カメラごとにwhile回してるところに持ってく
	c = ft_inner_product(cy->vctoc, cy->vno);
	b = ft_inner_product(vray, cy->vctoc)  - c * a;
	c = ft_v_d_len(cy->vctoc) - c * c - cy->d * cy->d / 4;
	d = ft_make_cy_sub(a, b, c, cy);
	// d = ft_quadratic_func((1 - a * a), b, c);
	// if (d == INFINITY)
	// 	return (INFINITY);
	// y = d * a  + ft_inner_product(cy->vctoc, cy->vno);;
	// if (0 <= y && y <= cy->h)
	// 	return (d);
	// else
	// {
	// 	d = d + 2 * sqrt(b * b - (1 - a * a) * c) / (1 - a * a);
	// 	y = d * a  + ft_inner_product(cy->vctoc, cy->vno);
	// 	if (0 <= y && y <= cy->h)
	// 		return (d);
	// 	return (INFINITY);
	// }
	return (d);
}

double ft_make_cy_sub(double a, double b, double c, t_gob *cy)
{
	double	tmp;
	double	d;
	double 	t;

	tmp = (1 - a * a);
	d = b * b - c * tmp;
	t = ft_quadratic_func(tmp, b, c);
	if (t < INFINITY)
	{
		cy->p2.y = t * a  + ft_inner_product(cy->vctoc, cy->vno);
		cy->p2.x = 1;
		if (0 <= cy->p2.y && cy->p2.y <= cy->h)
			return (t);
		else
		{
			t = t + 2 * sqrt(d) / tmp;
			cy->p2.y = t * a  + ft_inner_product(cy->vctoc, cy->vno);
			cy->p2.x = 2;
			if (0 <= cy->p2.y && cy->p2.y <= cy->h)
				return (t);
		}
	}
	return (INFINITY);
}

//解の存在が確認されているなら，
//a正の時
//c < 0 だったら，(-b  + sqrt(b ^2 - 4ac))/2
//c >= 0 かつ b /2 > 0だったら，(-b - sqrt(b^2 - 4ac))/2
//負の時
//c > 0 だったら，(-b + sqrt(b ^2 - 4ac))/2
//c <= 0 かつ b /2 > 0だったら，(-b - sqrt(b^2 - 4ac))/2

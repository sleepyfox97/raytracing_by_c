#include "./miniRT.h"

void	ft_diffusion_light_cy(t_cam *cam, t_light *l, t_gob *cy)
{
	double	cos1;
	double	cos2;
	t_vec3	p;
	t_vec3	vncp;//中心軸から，pへのベクトル
	t_vec3	v1;

	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);//何回も計算してるから，保存しとくのが良さげ．
	vncp = ft_linear_transform(cy->vno, cy->p1, cy->p2.y, 1);
	if (cy->p2.x == 1)
		vncp = ft_linear_transform(p, vncp, 1, -1);
	else
		vncp = ft_linear_transform(vncp, p, 1, -1);
	vncp = ft_make_unitvec(vncp);
	v1 = ft_linear_transform(l->p, p, 1, -1);
	v1 = ft_make_unitvec(v1);
	cos1 = ft_inner_product(vncp, v1);
	if (cos1 > 0 && !iscycross(cy, l->p, p))//自分自身との交差判定ここでしてる．
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, cy->color, cos1 * l->r);
	else
		return ;
	p = ft_linear_transform(v1, vncp, (-2) * cos1, 1);
	p = ft_make_unitvec(p);
	cos2 = ft_inner_product(cam->vray, p);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 0.6;//正の時に2乗しないとダメ．
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, cy->color, cos2);
	}
	return ;
}

//計算の精度の問題で，0とinfあたりをぐるぐるしてしまい，正確にtの値が取れていない．
//本来，infの場所が，なぜか，0前後で判断されてしまっている．(実際，dそのものから，出してるからそうなる)
//lightの場所から伸ばした，直線が，二箇所と交わるかの判断をする方で考えることにする？
int	iscycross(t_gob *cy, t_vec3 lp, t_vec3 p)//
{
	t_vec3	tmp;
	double	l;
	double	t;

	if (cy->p2.x == 1)
		return (0);
	tmp = ft_linear_transform(lp, p, -1, 1);
	l = sqrt(ft_v_d_len(tmp));
	tmp = ft_make_unitvec(tmp);
	t = ft_make_cy(cy, tmp, lp);
	if ( 0 < t && t < l - 0.00001)
		return (1);
	return (0);
}
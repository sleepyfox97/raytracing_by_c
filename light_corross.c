#include "./miniRT.h"

//cylinderの時だけ，自分自身のためにできる影の考慮をする必要あり．
int	ft_iscross(t_gob *ob, t_light *l, t_cam *cam)
{
	int i;
	int tmp;

	i = 0;
	tmp = ob->obnum;
	while (1)
	{
		ob = ob->next;
		if (ob->obnum == tmp || i == 1)
			break;
		if (ob->type == 1)
		{
			i = iscross_sp(ob, l->p, cam);
		}
		else if (ob->type == 2)
			i = iscross_pl(ob, l->p, cam);
		else if (ob->type == 3)
			i = iscross_sq(ob, l->p, cam);
		else if (ob->type == 5)
			i = iscross_tr(ob, l->p, cam);
		// else if (ob->type == 5)
		// 	i = iscross_cy(ob, l->p, cam);
	}
	return (i);
}

int iscross_sp(t_gob *sp, t_vec3 lp, t_cam *cam)
{
	t_vec3	tmp1;
	t_vec3	tmp2;
	double	tmp;
	double	a;
	double	b;
	double	c;

	//rayと物体のぶつかる場所の座標
	tmp1 = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	//上で出した座標からlightへの方向ベクトル
	tmp2 = ft_linear_transform(lp, tmp1, 1, -1);
	sp->h = ft_v_d_len(tmp2);
	tmp2 = ft_make_unitvec(tmp2);//ここをunitにしてないと，光源に向かうベクトルと，球との距離がきちんととれない．
	//tmp1の場所から，今注目してる球の中心の座標を引いたベクトル
	tmp1 = ft_linear_transform(tmp1, sp->p1, 1, -1);
	a = ft_v_d_len(tmp2);
	b = ft_inner_product(tmp1, tmp2);
	c = ft_v_d_len(tmp1) - sp->d * sp->d / 4;
//光源が手前にあるか判定をいれる．その時にunit vectorにするのを忘れない．
	if(ft_quadratic_func(a, b, c) < sqrt(sp->h))
			return (1);
	else
		return (0);
}

//怪しいので，後で確認入れた方がいいかもしれん．間違えてるから，うまくいかないのら～～～
//平面は無限に伸びてるので，光と平面どっちが手前に来てるかの判断を入れないといけない．
int	iscross_pl(t_gob *pl, t_vec3 lp, t_cam *cam)
{
	t_vec3	tmp1;
	t_vec3	tmp2;
	t_vec3	tmp3;
	double	a;
	double	b;

	//rayと物体のぶつかる場所
	tmp1 = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);//これ保存しておけば，毎回計算しなくて済む．
	//tmp1の場所からlightへの方向ベクトル
	tmp2 = ft_linear_transform(lp, tmp1, 1, -1);
	tmp3 = ft_make_unitvec(tmp2);//ここ忘れてた．
	a = ft_inner_product(tmp3, pl->vno);
	b = ft_inner_product(ft_linear_transform(tmp1, pl->p1, -1, 1), pl->vno);
	if (a == 0 || (b / a)< 0 || (b / a) > sqrt(ft_v_d_len(tmp2)))
		return (0);
	else
		return (1);
}

int	iscross_sq(t_gob *sq, t_vec3 lp, t_cam *cam)
{
	t_vec3	p;
	t_vec3	tmp1;
	double d;

	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);//これ保存しておけば，毎回計算しなくて済む．
	tmp1 = ft_linear_transform(lp, p, 1, -1);//lightごとに計算して渡す方が賢い気がする．
	d = ft_make_sq(sq, ft_make_unitvec(tmp1), p);
	if (d < sqrt(ft_v_d_len(tmp1)))//tmp1の二乗はlightまでの距離のこと
		return (1);
	return (0);
}

int	iscross_tr(t_gob *tr, t_vec3 lp, t_cam *cam)
{
	t_vec3 p;
	t_vec3 tmp1;
	double d;
	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	tmp1 = ft_linear_transform(lp, p, 1, -1);
	d = ft_make_tr(tr, ft_make_unitvec(tmp1), p);
	if (d < sqrt(ft_v_d_len(tmp1)))//tmp1の二乗はlightまでの距離のこと
		return (1);
	return (0);
}

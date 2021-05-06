#include "./miniRT.h"

//rayの方向とplの方向が平行になったら平面映らなくなるから注意．
double	ft_pl_color(t_gob *pl, t_cam *cam, t_light *l, t_amblight al)
{
	double	t;
	t_light	*ltmp;

	t = ft_make_pl(pl, cam->vray, cam->p);
	if (cam->distance > t && t > 0 )
	{
		cam->distance = t;
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al);
		ltmp = l;
		while (l != NULL)
		{
			if (!ft_iscross(pl, l, cam))
				ft_diffusion_light_pl(cam, l, pl);
			l = l->next;
		}
		l = ltmp;
	}
	return (cam->distance);
}

//vrayは必ず正規化されてないとだめ
double	ft_make_pl(t_gob *pl, t_vec3 vray, t_vec3 camp)
{
	double	tmp1;
	double	tmp2;
	t_vec3	vptoc;

	tmp1 = ft_inner_product(vray, pl->vno);
	vptoc = ft_linear_transform(camp, pl->p1, -1, 1);//ここじゃなくて，準備段階で計算できる．
	tmp2 = ft_inner_product(vptoc, pl->vno);
	if (tmp1 == 0)
		return (INFINITY);
	else
		return (tmp2 / tmp1);
}
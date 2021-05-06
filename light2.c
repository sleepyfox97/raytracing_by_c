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
	if (cos1 > 0)
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, cy->color, cos1 * l->r);
	//p = 
	return ;
}
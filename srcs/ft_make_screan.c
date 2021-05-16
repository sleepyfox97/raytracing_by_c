#include "./miniRT.h"

t_cam	*ft_make_screan_base(t_cam *cam)
{
	cam->vsb1 = make_screan_util1(cam->vd);
	cam->vsb2 = make_screan_util2(cam->vd, cam->vsb1);
	return (cam);
}

t_vec3	make_screan_util2(t_vec3 vd, t_vec3 vsb1)
{
	t_vec3	vsb2;

	if (vd.z == 0)
		vsb2 = ft_set_vecele(0, 0, 1);
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
		vsb1 = ft_set_vecele(0, -1, 0);
	else if (vd.y == 0 && vd.x < 0)
		vsb1 = ft_set_vecele(0, 1, 0);
	else
	{
		if (vd.y < 0)
			vsb1.x = -1;
		else
			vsb1.x = 1;
		vsb1.z = 0;
		vsb1.y = (-1) * (vd.x * vsb1.x) / vd.y;
	}
	vsb1 = ft_make_unitvec(vsb1);
	return (vsb1);
}

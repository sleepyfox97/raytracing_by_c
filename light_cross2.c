#include "./miniRT.h"

int	iscross_cy(t_gob *cy, t_vec3 lp, t_cam *cam)
{
	t_vec3	p;
	t_vec3	tmp1;
	double	t;

	p = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	tmp1 = ft_linear_transform(lp, p, 1, -1);
	t = ft_make_cy(cy, ft_make_unitvec(tmp1), p);
	if (t * t < ft_v_d_len(tmp1))
		return (1);
	return (0);
}

#include "./miniRT.h"

t_vec3	ft_make_ray(t_cam *cam, double x, double y)
{
	t_vec3	vray;
	t_vec3	vtmp;

	vtmp = ft_linear_transform(cam->vsb1, cam->vsb2, x, y);
	vray = ft_linear_transform(vtmp, cam->vptos, 1, 1);
	vray = ft_make_unitvec(vray);
	return (vray);
}
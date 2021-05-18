#include "./miniRT.h"

t_vec3	ft_set_vecele(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	ft_put_vector(t_vec3 v)
{
	printf("v.x=%f, v.y=%f, v.z=%f\n", v.x, v.y, v.z);
	return ;
}

int	ft_isnormal(t_vec3 *v)
{
	if (v->x < -1 || 1 < v->x)
		return (0);
	if (v->y < -1 || 1 < v->y)
		return (0);
	if (v->z < -1 || 1 < v->z)
		return (0);
	if (v->x == 0 && v->y == 0 && v->z == 0)
		return (0);
	*v = ft_make_unitvec(*v);
	return (1);
}

//not use these function
t_vec3	ft_gramschmidt_1(t_vec3 v1, t_vec3 v2)
{
	double	a;

	a = (ft_inner_product(v1, v2) / ft_v_d_len(v1));
	v2 = ft_linear_transform(v2, v1, 1, (-1) * a);
	return (v2);
}

t_vec3	ft_gramschmidt_2(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	double	a;
	double	b;
	t_vec3	tmp_vec;

	a = (ft_inner_product(v1, v3) / ft_v_d_len(v1));
	b = (ft_inner_product(v2, v3) / ft_v_d_len(v2));
	tmp_vec = ft_linear_transform(v1, v2, a, b);
	v3 = ft_linear_transform(v3, tmp_vec, 1, -1);
	printf("a = %lf  b = %lf\n", a, b);
	return (v3);
}

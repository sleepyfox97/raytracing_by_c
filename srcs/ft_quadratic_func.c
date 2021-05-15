#include "./miniRT.h"

//return value is always plus.
//you have to check first agument is always plus.
double	ft_quadratic_func(double a, double b, double c)
{
	double	d;

	d = b * b - a * c;
	if (d > 0)
	{
		if ((-1) * b - sqrt(d) > 0)
			return (((-1) * b - sqrt(d)) / a);
		else if ((-1) * b + sqrt(d) <= 0)
			return (INFINITY);
		else
			return (((-1) * b + sqrt(d)) / a);
	}
	else
		return (INFINITY);
}

#include "./miniRT.h"

int	isin_sphere(t_cam *cam, t_gob *ob)
{
	double	a;
	double	b;
	double	c;
	double	tmp;

	while (1)
	{
		if (ob->type == 1)
		{
			a = cam->p.x - ob->p1.x;
			b = cam->p.y - ob->p1.y;
			c = cam->p.z - ob->p1.z;
			tmp = a * a + b * b + c * c;
			if (tmp <= ob->d * ob->d / 4)
				return (1);
		}
		ob = ob->next;
		if (ob->obnum == 1)
			break ;
	}
	return (0);
}

void	ft_set_black(int *image, double width, double hight)
{
	int	tmp;
	int	i;

	tmp = (int)(width * hight);
	i = 0;
	while (i < tmp)
	{
		image[i] = 0;
		i++;
	}
	return ;
}

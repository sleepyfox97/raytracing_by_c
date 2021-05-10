#include "./miniRT.h"

void	print_minirt_struct(t_minirt *minirt)
{
	print_window_al(minirt);
	print_struct_light(minirt->firstlight);
	print_struct_cam(minirt->firstcam);
	print_struct_gob(minirt->firstgob);
}

void	print_window_al(t_minirt *minirt)
{
	if (minirt->width != -1 && minirt->hight != -1)
	{
		printf("\x1b[36m===this is window information====\033[m\n");
		printf("width = %lf\n", minirt->width);
		printf("hight = %lf\n", minirt->hight);
	}
	if (minirt->al.flag == 1)
	{
		printf("\n\x1b[36m======this is ambient light======\033[m\n");
		printf("ambient light ratio = \x1b[33m%lf\033[m\n", minirt->al.r);
		print_color(&(minirt->al.color));
	}
	return ;
}

void	print_struct_light(t_light *first)
{
	int	i;

	i = 1;
	while (first != NULL)
	{
		printf("\n\x1b[33m=========This is %d light=========\033[m\n", i);
		printf("light place \n");
		ft_put_vector(first->p);
		printf("\nlight strenght ratio = \x1b[33m%lf\033[m\n\n", first->r);
		print_color(&(first->color));
		first = first->next;
		i++;
	}
	return ;
}

void	print_struct_cam(t_cam *first)
{
	int	i;

	i = 1;
	while (first != NULL)
	{
		printf("\n\x1b[35m========This is %d camera=========\033[m\n", i);
		printf("camera place \n");
		ft_put_vector(first->p);
		printf("\nnormalized orientation vector of camera\n");
		ft_put_vector(first->vd);
		printf("\ncamera's fov = %lf\n", first->fov);
		first = first->next;
		i++;
	}
	return ;
}

void	print_color(t_color *color)
{
	printf("R : \x1b[31m%lf\x1b[39m\n", color->r);
	printf("G : \x1b[32m%lf\x1b[39m\n", color->g);
	printf("B : \x1b[34m%lf\x1b[39m\n", color->b);
}

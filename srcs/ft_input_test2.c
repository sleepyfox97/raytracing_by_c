#include "./miniRT.h"

void	print_struct_gob(t_gob *firstgob)
{
	int	i;

	i = 1;
	while (firstgob != NULL)
	{
		printf("\n\x1b[32m=======This is %d object=======\033[m\n", i);
		printf("type = %d\n", firstgob->type);
		print_struct_gob_type123(firstgob);
		print_struct_gob_type45(firstgob);
		firstgob = firstgob->next;
		i++;
	}
	return ;
}

void	print_struct_gob_type123(t_gob *firstgob)
{
	if (firstgob->type == 1)
	{
		printf("this is sphere\n\nplace of center\n");
		ft_put_vector(firstgob->p1);
		printf("\ndiameter = %lf\n", firstgob->d);
		print_color(&(firstgob->color));
		printf("\nsp->next = %p\n", firstgob->next);
	}
	else if (firstgob->type == 2)
	{
		printf("this is plane\n\ncoordinates of point on the plane\n");
		ft_put_vector(firstgob->p1);
		printf("\nnormalized orientation vector\n");
		ft_put_vector(firstgob->vno);
		print_color(&(firstgob->color));
	}
	else if (firstgob->type == 3)
	{
		printf("this is square\n\ncoordinates of point on the square\n");
		ft_put_vector(firstgob->p1);
		printf("\nnormalized orientation vector\n");
		ft_put_vector(firstgob->vno);
		printf("\nside size = %lf\n", firstgob->d);
		print_color(&(firstgob->color));
	}
}

void	print_struct_gob_type45(t_gob *firstgob)
{
	if (firstgob->type == 4)
	{
		printf("this is cylinder\n");
		printf("coordinates of point on the square\n");
		ft_put_vector(firstgob->p1);
		printf("\nnormalized orientation vector\n");
		ft_put_vector(firstgob->vno);
		printf("\ndiameter = %lf\n", firstgob->d);
		printf("\nhight = %lf\n", firstgob->h);
		print_color(&(firstgob->color));
	}
	else if (firstgob->type == 5)
	{
		printf("this is triangle\n");
		printf("coordinates of point on the square\n");
		ft_put_vector(firstgob->p1);
		printf("coordinates of point on the square\n");
		ft_put_vector(firstgob->p2);
		printf("coordinates of point on the square\n");
		ft_put_vector(firstgob->p3);
		print_color(&(firstgob->color));
	}
}

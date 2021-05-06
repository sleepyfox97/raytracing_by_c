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
	int i = 1;
	while(first != NULL)
	{
		printf("\n\x1b[33m=========This is %d light=========\033[m\n", i);
		printf("light place \n");
		ft_put_vector(first->p);
		printf("\nlight strenght ratio = \x1b[33m%lf\033[m\n\n",first->r);
		print_color(&(first->color));
		first = first->next;
		i++;
	}
	return ;
}

void	print_struct_cam(t_cam *first)
{
	int i = 1;
	while(first != NULL)
	{
		printf("\n\x1b[35m========This is %d camera=========\033[m\n", i);
		printf("camera place \n");
		ft_put_vector(first->p);
		printf("\nnormalized orientation vector of camera\n");
		ft_put_vector(first->vd);
		printf("\ncamera's fov = %lf\n",first->fov);
		first = first->next;
		i++;
	}
	return ;
}


void	print_struct_gob(t_gob *firstgob)
{
	int i = 1;
	while(firstgob != NULL)
	{
		printf("\n\x1b[32m=======This is %d object=======\033[m\n", i);
		printf("type = %d\n", firstgob->type);
		if (firstgob->type == 1)
		{
			printf("this is sphere\n\n");
			printf("place of center\n");
			ft_put_vector(firstgob->p1);
			printf("\ndiameter = %lf\n", firstgob->d);
			print_color(&(firstgob->color));

			printf("\nsp->next = %p\n", firstgob->next);
		}
		else if (firstgob->type == 2)
		{
			printf("this is plane\n\n");
			printf("coordinates of point on the plane\n");
			ft_put_vector(firstgob->p1);
			printf("\nnormalized orientation vector\n");
			ft_put_vector(firstgob->vno);
			print_color(&(firstgob->color));
			//printf("color = %X\n", firstgob->color);
		}
		else if (firstgob->type == 3)
		{
			printf("this is square\n");
			printf("coordinates of point on the square\n");
			ft_put_vector(firstgob->p1);
			printf("\nnormalized orientation vector\n");
			ft_put_vector(firstgob->vno);
			printf("\nside size = %lf\n", firstgob->d);
			print_color(&(firstgob->color));
			//printf("color = %X\n", firstgob->color);
		}
		else if (firstgob->type == 4)
		{
			printf("this is cylinder\n");
			printf("coordinates of point on the square\n");
			ft_put_vector(firstgob->p1);
			printf("\nnormalized orientation vector\n");
			ft_put_vector(firstgob->vno);
			printf("\ndiameter = %lf\n", firstgob->d);
			printf("\nhight = %lf\n", firstgob->h);
			print_color(&(firstgob->color));
			//printf("color = %X\n", firstgob->color);
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
			//printf("color = %X\n", firstgob->color);
		}
		firstgob = firstgob->next;
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

// int main()
// {
// 	char *line1 = "sp     0.0,0.0,20.6         12.6   255,0,255";
// 	char *line2 = "sp     0.1,0.1,0.24         99.9   31,31,31";
// 	char *line3 = "pl     0.0,0.0,0.3      0.0,1,0.0   3,3,3";
// 	char *line4 = "sq    0.0,0.0,0.3      0.0,1,0.0  214.412   7,7,7";
// 	char *line5 = "cy    50.0,0.0,20.6      0.0,0.0,1.0  14.2   21.42  15,15,15";
// 	char *line6 = "tr    50.0,0.0,20.6      0.0,0.0,1.0   0.0,0.0,20.6  127,127,127";
// 	t_minirt minirt;
// 	int i = 0;

// 	minirt.firstgob = NULL;
// 	i = ft_object_input(&minirt, line1);
// 	printf("i=%d\n", i);
// 	i = ft_object_input(&minirt, line2);
// 	printf("i=%d\n", i);
// 	i = ft_object_input(&minirt, line3);
// 	printf("i=%d\n", i);
// 	i = ft_object_input(&minirt, line4);
// 	printf("i=%d\n", i);
// 	i = ft_object_input(&minirt, line5);
// 	printf("i=%d\n", i);
// 	i = ft_object_input(&minirt, line6);
// 	printf("i=%d\n", i);
// 	print_struct_gob(minirt.firstgob);
// 	return (0);
// }


//read RTfile2


// int main()
// {
// 	t_minirt minirt;
// 	char *line1 = "A           0.5        255,255,255";
// 	char *line2 = "l       -40.0,50.0,0.0   0.6  10,0,255";
// 	minirt.firstlight = NULL;
// 	// int i = ft_amblight_input(&(minirt.al), line1);
// 	// printf("A r = %lf color=%X\n", minirt.al.r, minirt.al.color);
// 	int i = ft_light_input(&(minirt.firstlight), line2);
// 	printf("i = %d\n", i);
// 	printf("l r = %lf color=%X\n", minirt.firstlight->r, minirt.firstlight->color);
// }





//for read RTfile1


// int main()
// {
// 	char *line = "R   510 500";
// 	int i = 0;
// 	t_minirt minirt;

// 	i = ft_windowinfo_input(&minirt, line);
// 	printf("%d\n%lf. %lf\n", i, minirt.width, minirt.hight);
// }

// int main()
// {
// 	char *line = "c   -50.0,0,20  0,..0,1 70  ";
// 	int i = 0;
// 	t_cam	*cam;
// 	t_vec3 a;

// 	// cam = (t_cam *)malloc(sizeof(t_cam));
// 	// i = get_two_vec(line, 2, &(cam->p), &(cam->vd));
// 	cam = NULL;
// 	i = ft_cam_imput(&cam, line);
// 	printf("i = %d\n", i);
// 	system("leaks a.out");
	// ft_put_vector(cam->p);
	// ft_put_vector(cam->vd);
	// printf("fov = %lf", cam->fov);
//}
// えらーケースの場合は，構造体自体がつながれずに終わってるので，注意


//for read only test

// int main(int argc, char *argv[])
// {
// 	t_minirt minirt;
// 	if(argc != 2)
// 		return (0);
// 	int i = 0;
// 	i = ft_get_info(&minirt, argv[1]);
// 	if (i != 0)
// 	{
// 		i = 0;
// 		while(minirt.test[i] != NULL)
// 		{
// 			printf("%s\n", minirt.test[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }
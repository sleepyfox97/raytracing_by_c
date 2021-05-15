#include "./miniRT.h"

void	print_prepare_cam(t_cam *first)
{
	int	i;

	i = 1;
	while (1)
	{
		printf("\n\x1b[35m========This is %d camera=========\033[m\n", i);
		printf("screan base vector 1 \n");
		ft_put_vector(first->vsb1);
		printf("\nscrean base vector 2\n");
		ft_put_vector(first->vsb2);
		printf("vctos\n");
		printf("fov = %lf", first->fov);
		printf("\nimage pointor\n");
		ft_put_vector(first->vptos);
		printf("*image =%p\n", first->image);
		printf("cam->next = %p\n", first->next);
		printf("cam       = %p\n", first);
		printf("cam->prev = %p\n", first->prev);
		first = first->next;
		if (first->cnum == 1)
			break ;
		i++;
	}
	return ;
}

void	print_prepare_obj(t_gob *first)
{
	int	i;

	i = 0;
	while (1)
	{
		printf("\n\x1b[32m=======This is %d object=======\033[m\n", i);
		printf("type = %d\n", first->type);
		printpre_type123(first);
		printpre_type4(first);
		printpre_type5(first);
		if (first->next->obnum == 1)
			break ;
		first = first->next;
		i++;
	}
}

void	printpre_type123(t_gob *first)
{
	if (first->type == 1)
	{
		printf("this is sphere\n\n");
		printf("sp->next = %p\n", first->next);
		printf("sp       = %p\n", first);
	}
	else if (first->type == 2)
	{
		printf("this is plane\n\n");
		printf("pl->next = %p\n", first->next);
		printf("pl       = %p\n", first);
	}
	else if (first->type == 3)
	{
		printf("this is square\n\n");
		printf("sq->next = %p\n", first->next);
		printf("sq       = %p\n", first);
		printf("base1\n");
		ft_put_vector(first->p2);
		printf("base2\n");
		ft_put_vector(first->p3);
	}
}

void	printpre_type4(t_gob *first)
{
	if (first->type == 4)
	{
		printf("this is cylinder\n\n");
		printf("pl->next = %p\n", first->next);
		printf("pl       = %p\n", first);
	}
}

void	printpre_type5(t_gob *first)
{
	if (first->type == 5)
	{
		printf("this is square\n\n");
		printf("sq->next = %p\n", first->next);
		printf("sq       = %p\n", first);
		printf("base1\n");
		ft_put_vector(first->vtb1);
		printf("base2\n");
		ft_put_vector(first->vtb2);
		printf("base3\n");
		ft_put_vector(first->vtb3);
		printf("base4\n");
		ft_put_vector(first->vctoc);
		printf("cos1(p1 centor) = %lf\n", first->d);
		printf("cos2(p2 centor)= %lf\n", first->h);
		printf("vno\n");
		ft_put_vector(first->vno);
	}
}

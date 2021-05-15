#include "./miniRT.h"

int	main(int argc, char *argv[])
{
	t_minirt	rt;

	ft_initialize_minirt(&rt);
	if (argc == 2)
	{
		if (!isrtfile(argv[1]))
			return (printf("Error\n\nthe file name should end \".rt\"."));
		ft_minirt(&rt, argv[1]);
		rt.win = mlx_new_window(rt.mlx, rt.width, rt.hight, "miniRT");
		ft_use_mlx(&rt);
	}
	else if (argc == 3)
	{
		if (!isrtfile(argv[1]))
			return (printf("Error\n\nthe file name should end \".rt\"."));
		if (!issave(argv[2]))
			return (printf("Error\n\nyou have to write \"--save\""));
		ft_minirt(&rt, argv[1]);
		make_bmpfile(&rt);
		exit(0);
	}
	else
		printf("Error\n\n\nArguments have to be 2 or 3.\n");
	return (0);
}

void	ft_minirt(t_minirt *minirt, char *argv)
{
	int	i;

	i = 0;
	i = ft_get_info(minirt, argv);
	if (i == 0)
	{
		exit (0);
		return ;
	}
	if (i == 1)
	{
		print_minirt_struct(minirt);
		if (!ft_prepare_print(minirt))
		{
			ft_clear_minirt(minirt);
			exit (0);
			return ;
		}
		ft_print_obj(minirt);
	}
	return ;
}

void	ft_initialize_minirt(t_minirt *minirt)
{
	minirt->firstcam = NULL;
	minirt->firstlight = NULL;
	minirt->firstgob = NULL;
	minirt->al.flag = -1;
	minirt->width = -1;
	minirt->hight = -1;
	minirt->keycode = -1;
	return ;
}

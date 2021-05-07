#include "./miniRT.h"


//argv[1]確認して，読み取りファイルをdefineする．
//00が頭にくる場合すべてatolではねるようにしたい．
//argv[1]が.rtで終わるファイルかを確認する．vnoが000の場合はerrorケース
//unirt vectorの大きさが0になる場合（全ての要素が0の時）をはじく．
//最後に全部freeする．
//カメラが一個もない時のerror処理．
//A.Rが一つしかないかを確認してerror処理．
//
int main(int argc, char *argv[])
{
	t_minirt	minirt;
	int			i;

	i = 0;
	ft_initialize_minirt(&minirt);
	if (argc != 2 && argc != 3)
	{
		printf("Error\n\nargument error.\nArguments have to be 2 or 3.\n");
		return (0);
	}
	else if(argc == 2) 
	{
		//if (is_rtfile(argv[1]))
			//return (printf("Errpr\n\nthe file name is not good."));
		ft_type2(&minirt, argv[1]);

		mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &param);

		mlx_loop(mlx_ptr);
		ft_show_image(minirt);
		printf("if this comment shows, You can write good code\n");
	}
	else if (argc == 3)
	{
		printf("I didn't make argc == 3 program\n");
	}
	return (0);
}

//3:free elements
void	ft_type2(t_minirt *minirt, char *argv)
{
	int i;

	i = 0;
	i = ft_get_info(minirt, argv);//A,R,cがない時，A，Rが二つある時のerror処理
	if (i == 0)
		return ;
	else if (i == 1)
	{
		print_minirt_struct(minirt);
		if(!ft_prepare_print(minirt))
			return ft_clear_minirt(minirt);
		print_prepare_cam(minirt->firstcam);
		print_prepare_obj(minirt->firstgob);
		ft_print_obj(minirt);

	}
	//free everything.
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
}

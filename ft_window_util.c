// #include "./miniRT.h"
// # define X_EVENT_KEY_PRESS		2
// # define X_EVENT_KEY_release	3
// # define X_EVENT_KEY_EXIT		17
// # define KEY_ESC			65307
// # define KEY_Q			12
// # define KEY_W			119
// # define KEY_E			14
// # define KEY_R			15
// # define KEY_A			97
// # define KEY_S			115
// # define KEY_D			2

// # define K_ESC		65307
// # define K_UP		65362
// # define K_DOWN		65364
// # define K_LEFT		65361
// # define K_RIGHT	65363
// # define K_A		97
// # define K_D		100
// # define K_W		119
// # define K_S		115

// //↑65362
// //↓65364
// //←65361
// //→65263
// //a  :　97
// //d  :  100
// //w  :  119
// //s  :  115
// //

// typedef struct s_param{
// 	int		x;
// 	int		y;
// 	char	str[3];
// }				t_param;

// //Only param->x will be used.
// void			param_init(t_param *param)
// {
// 	param->x = 3;
// 	param->y = 4;
// 	param->str[0] = 'a';
// 	param->str[1] = 'b';
// 	param->str[2] = '\0';
// }

// int				key_press(int keycode, t_param *param)
// {
// 	static int a = 0;

// printf("i = %d\n", keycode);
// 	if (keycode == KEY_W)//Action when W key pressed
// 		param->x++;
// 	else if (keycode == KEY_S) //Action when S key pressed
// 		param->x--;
// 	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
// 		exit(0);
// 	printf("x: %d\n", param->x);
// 	return (0);
// }

// int			main(void)
// {
// 	void		*mlx;
// 	void		*win;
// 	t_param		param;

// 	param_init(&param);
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "mlx_project");
// 	printf("-------------------------------\n");
// 	printf("'W key': Add 1 to x.\n");
// 	printf("'S key': Subtract 1 from x\n");
// 	printf("'ESC key': Exit this program\n");
// 	printf("'Other keys': print current x \n");
// 	printf("-------------------------------\n");
// 	printf("Current x = 3\n");
// 	mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &param);
// 	mlx_loop(mlx);
// }

// // typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	ft_close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// 	return (1);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
// 	mlx_loop(vars.mlx);
// 	return (0);
// }



// #include "./miniRT.h"
// #define K_WL = 119;
// #define K_WS = 87;
// #define K_AL = 97;
// #define K_AS = 65;
// #define K_DL = 98;
// #define K_DS =
//minirt->w
//int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*funct)(),void *param)
//第一引数にwindowのポインタ，第二引数にkye，第三引数に1L<<0 or 1L<<17を入れる．
//第四引数に関数ポインタを入れる．
//
// int	kye_input(int keycode, t_minirt *minirt)
// {
// 	if (keycode == K_ESC)
// 		//game_kye_wd
// 	else if (kyecode == K_WL)
// 		//
// 	else if (kyecodd == K )
// }
// int    game_key(int keycode, t_game *game)
// {
//     if (keycode == KEY_W)
//         game_key_wd(
//             &game->cubstat, &game->sys, game->sys.dir_x, game->sys.dir_y);
//     else if (keycode == KEY_A)
//         game_key_as(
//             &game->cubstat, &game->sys, game->sys.plane_x, game->sys.plane_y);
//     else if (keycode == KEY_S)
//         game_key_as(
//             &game->cubstat, &game->sys, game->sys.dir_x, game->sys.dir_y);
//     else if (keycode == KEY_D)
//         game_key_wd(
//             &game->cubstat, &game->sys, game->sys.plane_x, game->sys.plane_y);
//     else if (keycode == KEY_RIGHT)
//         game_key_rotate(
//             &game->cubstat, &game->sys, -1);
//     else if (keycode == KEY_LEFT)
//         game_key_rotate(
//             &game->cubstat, &game->sys, 1);
//     else if (keycode == KEY_ESC)
//         exit(0);
// }
//windowのリサイズ対応．
//キー入力対応
//表示のスピード上げる．
//int mlx_hook関数を使う．
//winを渡して，
//x_evetがキー入力とか
//何を読み取るかによって，数字が変わる．1l<<0でキー入力を受け取ることになる．
//システムコールの呼び出しの数字がこの上の数字らしい．
//
//その後ろに関数ポインタを入れて，その関数の中で使う，構造体を
//キーコードはなんか検索すれば分かる．
//x_evetの数字も決まってて，window閉じるときは33って決まってる．
//x_maskの数字は，windowとじる時に1L << 17
//colseしてexitするのがいい．
// mlx_hook(game.sys.win, 2, 1L << 0, game_key, &game);
// mlx_hook(game.sys.win, 33, 1L << 17, close_window, &game);
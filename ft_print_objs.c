#include "./miniRT.h"

void	ft_print_obj(t_minirt *minirt)
{
	int i;
	int j;
	double x;
	double y;
	t_gob	*tmp;

	tmp = minirt->firstgob;
	while (1)
	{
		i = 0;
		ft_light_prepare(minirt->firstlight, minirt->firstcam);
		//カメラごとにsceneをいれる関数を作る．
		while (i < (int)minirt->width)
		{
			x = i - minirt->width / 2;
			j = 0;
			while (j < (int)minirt->hight)
			{
				minirt->firstgob = tmp;//無くても動くはず
				y = (-1) * (j - minirt->hight / 2);
				minirt->firstcam->image[i * (int)minirt->hight + j] = ft_calcu_color(minirt, x, y);
				j++;
			}
			i++;
		}
		if (minirt->firstcam->next->cnum == 1)
			break ;
		minirt->firstcam = minirt->firstcam->next;
	}
}

int	ft_calcu_color(t_minirt *rt, double x, double y)//名前変えるgit 
{
	int color;
	t_color	c;

	rt->firstcam->distance = INFINITY;
	rt->firstcam->vray = ft_make_ray(rt->firstcam, x, y);
	rt->firstcam->tmpcolor = ft_set_color(0, 0, 0);
	while (1)
	{
		if (rt->firstgob->type == 1)
			ft_sp_color(rt->firstgob, rt->firstcam ,rt->firstlight, rt->al);
		else if (rt->firstgob->type == 2)
			ft_pl_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 3)
			ft_sq_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 4)
			ft_cy_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		else if (rt->firstgob->type == 5)
			ft_tr_color(rt->firstgob, rt->firstcam, rt->firstlight, rt->al);
		if (rt->firstgob->next->obnum == 1)
			break ;
		rt->firstgob = rt->firstgob->next;
	}
	c = rt->firstcam->tmpcolor;
	color = (int)c.r << 16 | (int)c.g << 8 | (int)c.b;
	return (color);
}

void	ft_show_image(t_minirt *minirt)
{
	int		i;
	int		j;
	int		*c;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, minirt->width, minirt->hight, "miniRT");
	c = minirt->firstcam->image;
	i = 0;
	while (i < minirt->width)
	{
		j = 0;
		while (j < minirt->hight)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, c[i * (int)minirt->hight + j]);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	return ;
}

int	ft_prepare_print(t_minirt *rt)
{
	t_gob *tmp;
	//windowサイズとvmの画面サイズを比較して，正しいサイズにwidthとhightを変更する関数用意
	if (!ft_cam_prepare(rt->firstcam, rt->width, rt->hight))
		return (0);
	ft_obj_prepare(rt->firstgob);
	return (1);
}

void	ft_light_prepare(t_light *flight, t_cam *cam)
{
	t_light *tmp1;
	int i;

	tmp1 = flight;
	i = 1;
	while (flight != NULL)
	{
		flight->lnum = i;
		flight->vctol = ft_linear_transform(flight->p, cam->p, 1, -1);
		i++;
		flight = flight->next;
	}
	flight = tmp1;
	return ;
}

int	ft_cam_prepare(t_cam *firstcam, double width, double hight)
{
	t_cam	*tmp1;
	t_cam	*tmp2;
	int		i;

	tmp1 = firstcam;
	i = 1;
	while(firstcam != NULL)
	{
		firstcam->fov = firstcam->fov * M_PI / 180;
		firstcam->vptos = ft_linear_transform
			(firstcam->vd, firstcam->vd, (width / (2 * (tan(firstcam->fov / 2)))), 0);
		firstcam = ft_make_screan_base(firstcam);
		firstcam->cnum = i;
		firstcam->image = (int *)malloc(sizeof(int) * width * hight);
		if (firstcam->image == NULL)
			return (0);
		if (firstcam->next == NULL)
			tmp2 = firstcam;
		firstcam = firstcam->next;
		i++;
	}
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	return (1);
}

void	ft_obj_prepare(t_gob *firstgob)
{
	t_gob	*tmp1;
	t_gob	*tmp2;
	int		i;

	tmp1 = firstgob;
	i = 1;
	while (firstgob != NULL)
	{
		firstgob->obnum = i;
		i++;
		if (firstgob->type == 3)
			ft_pre_sq(firstgob);
		else if (firstgob->type == 5)
			ft_pre_tr(firstgob);
		if (firstgob->next == NULL)
			tmp2 = firstgob;
		firstgob = firstgob->next;
		i++;
	}
	tmp2->next = tmp1;
	return ;
}

void	ft_pre_sq(t_gob *sq)
{
	sq->p2 = make_screan_util1(sq->vno);//準備段階に投げられる
	sq->p3 = make_screan_util2(sq->vno, sq->p2);//準備段階に投げられる．
	return ;
}

void	ft_pre_tr(t_gob *tr)
{
	tr->vtb1 = ft_linear_transform(tr->p2, tr->p1, 1, -1);
	tr->vtb2 = ft_linear_transform(tr->p3, tr->p1, 1, -1);
	tr->vtb3 = ft_linear_transform(tr->p3, tr->p2, 1, -1);
	tr->vctoc = ft_linear_transform(tr->p1, tr->p2, 1, -1);
	tr->vtb1 = ft_make_unitvec(tr->vtb1);
	tr->vtb2 = ft_make_unitvec(tr->vtb2);
	tr->vtb3 = ft_make_unitvec(tr->vtb3);
	tr->vctoc = ft_make_unitvec(tr->vctoc);
	tr->vno = ft_cross_product(tr->vtb1, tr->vtb2);
	tr->vno = ft_make_unitvec(tr->vno);
	tr->d = ft_inner_product(tr->vtb1, tr->vtb2);//p1中心
	tr->h = ft_inner_product(tr->vctoc, tr->vtb3);//p2中心
	return ;
}

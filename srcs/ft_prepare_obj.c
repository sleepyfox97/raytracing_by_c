#include "./miniRT.h"

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
	sq->p2 = make_screan_util1(sq->vno);
	sq->p3 = make_screan_util2(sq->vno, sq->p2);
	sq->d = sq->d / 2;
	return ;
}

//tr->d is centor of p1
//tr->h is centor of p2
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
	tr->d = ft_inner_product(tr->vtb1, tr->vtb2);
	tr->h = ft_inner_product(tr->vctoc, tr->vtb3);
	return ;
}

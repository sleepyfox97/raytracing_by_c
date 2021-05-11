#include "./miniRT.h"

void	ft_progress(t_minirt *rt, int i, t_cam *cam)
{
	if (i == (int)(rt->hight / 10))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight / 5))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 3 / 10))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 4 / 10))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight / 2))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 3 / 5))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 7 / 10))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 4 / 5))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight * 9 / 10))
		printf("\x1b[36m>\x1b[39m");
	else if (i == (int)(rt->hight))
		printf("\x1b[36m>\x1b[39m\ncamera %d calculattion done\n", cam->cnum);
	return ;
}

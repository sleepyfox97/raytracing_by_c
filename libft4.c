#include "./miniRT.h"

void	ft_clear_minirt(t_minirt *minirt)
{
	ft_camlstclear(minirt->firstcam);
	ft_lightlstclear(minirt->firstlight);
	ft_oblstclear(minirt->firstgob);
}

void	ft_camlstclear(t_cam *firstcam)
{
	t_cam	*tmp;

	while (firstcam != NULL)
	{
		tmp = firstcam->next;
		firstcam->prev = NULL;
		firstcam->next = NULL;
		free(firstcam);
		firstcam = tmp;
	}
	return ;
}

void	ft_lightlstclear(t_light *firstlight)
{
	t_light	*tmp;

	while (firstlight != NULL)
	{
		tmp = firstlight->next;
		firstlight->next = NULL;
		free(firstlight);
		firstlight = tmp;
	}
	return ;
}

void	ft_oblstclear(t_gob *firstgob)
{
	t_gob	*tmp;

	while (firstgob != NULL)
	{
		tmp = firstgob->next;
		firstgob->prev = NULL;
		firstgob->next = NULL;
		free(firstgob);
		firstgob = tmp;
	}
	return ;
}

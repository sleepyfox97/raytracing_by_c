#include "miniRT.h"

//循環リストは，最初は双方向リストとして扱い，最後にくっつけることで実現する．

int	ft_cam_input(t_cam **firstcam, char *line)
{
	int		i;
	t_cam	*new;

	new = (t_cam *)malloc(sizeof(t_cam));
	if (!new)
		return (0);
	i = 1;
	i = get_two_vec(line, i, &(new->p), &(new->vd));
	if (i == 0 || !ft_isnormal(&(new->vd)))//各成分が±1の範囲にあれば正規化して返す．
		return (ft_safe_free1(new));
	i = get_fov(line, i, &(new->fov));
	if (i == 0)
		return (ft_safe_free1(new));
	if (*firstcam == NULL)
	{
		*firstcam = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = ft_camlstlast(*firstcam);
		ft_camlstlast(*firstcam)->next = new;
	}
	new->next = NULL;
	return (1);
}

int	ft_windowinfo_input(t_minirt *minirt, char *line)
{
	int	i;

	i = 1;
	if (minirt->width != -1 || minirt->hight != -1)
		return (0);
	i = ft_atol(line, i, &(minirt->width));
	if (i == 0)
		return (0);
	i = ft_atol(line, i, &(minirt->hight));
	if (i == 0)
		return (0);
	if (line[i] != '\0' && line[i] != 13)
		return (0);
	return (1);
}

int	ft_light_input(t_light **firstlight, char *line)
{
	int		i;
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		return (0);
	i = 1;
	if (!ft_isspace(line[i]))
		return (ft_safe_free1(new));
	i = get_pv(line, i, &(new->p));
	if (i == 0 || !ft_isspace(line[i]))
		return (ft_safe_free1(new));
	i = ft_atof(line, i, &(new->r));
	if (i == 0 || !ft_isspace(line[i]) || ((new->r) < 0 && 1 < (new->r)))
		return (ft_safe_free1(new));
	i = ft_get_color(line, i, &(new->color));
	if (i == 0 || (line[i] != '\0' && line[i] != 13))
		return (ft_safe_free1(new));
	if (*firstlight == NULL)
		*firstlight = new;
	else
		ft_lightlstlast(*firstlight)->next = new;
	new->next = NULL;
	return (1);
}

int	ft_amblight_input(t_amblight *al, char *line)
{
	int	i;

	i = 1;
	if (al->flag != -1)
		return (0);
	if (!ft_isspace(line[i]))
		return (0);
	i = ft_atof(line, i, &(al->r));
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	i = ft_get_color(line, i, &(al->color));
	if (i == 0 || (line[i] != '\0' && line[i] != 13))
		return (0);
	al->flag = 1;
	return (1);
}

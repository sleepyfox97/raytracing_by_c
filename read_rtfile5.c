#include "./miniRT.h"

int	ft_square_input(t_gob **firstgob, char *line)
{
	int		i;
	t_gob	*new;

	new = (t_gob *)malloc(sizeof(t_gob));
	if (!new)
		return (0);
	i = 2;
	new->type = 3;
	i = ft_input_SqAndCy_sub(new, line, i);
	if (i == 0)
		return (ft_safe_free1(new));
	i = ft_get_color(line, i, &(new->color));
	if (i == 0 || line[i] != '\0')
		return (ft_safe_free1(new));
	if (*firstgob == NULL)
		*firstgob = new;
	else
		ft_oblstlast(*firstgob)->next = new;
	new->next = NULL;
	return (1);
}

int	ft_cylinder_input(t_gob **firstgob, char *line)
{
	int		i;
	t_gob	*new;

	new = (t_gob *)malloc(sizeof(t_gob));
	if (!new)
		return (0);
	i = 2;
	new->type = 4;
	i = ft_input_SqAndCy_sub(new, line, i);
	if (i == 0)
		return (ft_safe_free1(new));
	i = ft_atof(line, i, &(new->h));
	if (i == 0 || !ft_isspace(line[i]) || (new->h) < 0)
		return (ft_safe_free1(new));
	i = ft_get_color(line, i, &(new->color));
	if (i == 0 || line[i] != '\0')
		return (ft_safe_free1(new));
	if (*firstgob == NULL)
		*firstgob = new;
	else
		ft_oblstlast(*firstgob)->next = new;
	new->next = NULL;
	return (1);
}

int	ft_input_SqAndCy_sub(t_gob *new, char *line, int i)
{
	if (!ft_isspace(line[i]))
		return (0);
	i = get_two_vec(line, i, &(new->p1), &(new->vno));
	if (i == 0 || !ft_isnormal(&(new->vno)))//±1の範囲にあれば，正規化して返す．
		return (0);
	i = ft_atof(line, i, &(new->d));
	if (i == 0 || !ft_isspace(line[i]) || (new->d) < 0)
		return (0);
	return (i);
}

int	ft_triangle_input(t_gob **firstgob, char *line)
{
	int		i;
	t_gob	*new;

	new = (t_gob *)malloc(sizeof(t_gob));
	if (!new)
		return (0);
	i = 2;
	new->type = 5;
	i = get_three_vec(line, i, &(new->p1), &(new->p2), &(new->p3));
	if (i == 0)
		return (ft_safe_free1(new));
	i = ft_get_color(line, i, &(new->color));
	if (i == 0 || line[i] != '\0')
		return (ft_safe_free1(new));
	if (*firstgob == NULL)
		*firstgob = new;
	else
		ft_oblstlast(*firstgob)->next = new;
	new->next = NULL;
	return (1);
}

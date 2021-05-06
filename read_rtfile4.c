#include "./miniRT.h"

int	ft_object_input(t_minirt *minirt, char *line)
{
	int	i;

	i = 0;
	i = ft_isobject(line);
	if (i == 0)
		return (0);
	else if (i == 1)
		i = ft_sphere_input(&(minirt->firstgob), line);
	else if (i == 2)
		i = ft_plane_input(&(minirt->firstgob), line);
	else if (i == 3)
		i = ft_square_input(&(minirt->firstgob), line);
	else if (i == 4)
		i = ft_cylinder_input(&(minirt->firstgob), line);
	else if (i == 5)
		i = ft_triangle_input(&(minirt->firstgob), line);
	if (i == 0)
		return (0);
	return (1);
}

int	ft_isobject(char *line)
{
	if (line[0] == 's' && line[1] == 'p')
		return (1);
	else if (line[0] == 'p' && line[1] == 'l')
		return (2);
	else if (line[0] == 's' && line[1] == 'q')
		return (3);
	else if (line[0] == 'c' && line[1] == 'y')
		return (4);
	else if (line[0] == 't' && line[1] == 'r')
		return (5);
	else
		return (0);
}

int	ft_sphere_input(t_gob **firstgob, char *line)
{
	int		i;
	t_gob	*new;

	new = (t_gob *)malloc(sizeof(t_gob));
	if (!new)
		return (0);
	i = 2;
	new->type = 1;
	if (!ft_isspace(line[i]))
		return (ft_safe_free1(new));
	i = get_pv(line, i, &(new->p1));
	if (i == 0 || !ft_isspace(line[i]))
		return (ft_safe_free1(new));
	i = ft_atof(line, i, &(new->d));
	if (i == 0 || !ft_isspace(line[i]) || (new->d) < 0)
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

int	ft_plane_input(t_gob **firstgob, char *line)
{
	int		i;
	t_gob	*new;

	new = (t_gob *)malloc(sizeof(t_gob));
	if (!new)
		return (0);
	i = 2;
	new->type = 2;
	if (!ft_isspace(line[i]))
		return (ft_safe_free1(new));
	i = get_two_vec(line, i, &(new->p1), &(new->vno));
	if (i == 0 || !ft_isnormal(&(new->vno)))//各成分が±1の範囲内にあるかを確認してたうえで，正規化されたベクトルを代入．
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

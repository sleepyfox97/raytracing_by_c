#include "./miniRT.h"

int	ft_get_info(t_minirt *minirt, char *argv)
{
	char	*line;
	char	**sp_line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	line = ft_read_rtfile(fd);
	sp_line = ft_split(line, '\n');
	free (line);
	if (!ft_input_info(minirt, sp_line))
		return (0);
	if (!ft_check_input(minirt))
		exit (0);
	return (1);
}

char	*ft_read_rtfile(int fd)
{
	char	*str;
	char	*line;
	ssize_t	buf;

	str = (char *)malloc(sizeof(char) * 1000);
	line = NULL;
	buf = 1;
	while (buf != 0)
	{
		buf = read(fd, str, 999);
		str[buf] = '\0';
		line = ft_strjoin(line, str);
		if (line == NULL)
		{
			free(str);
			return (NULL);
		}
	}
	free(str);
	return (line);
}

int	ft_input_info(t_minirt *minirt, char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (line[i] != NULL)
	{
		j = 0;
		j = ft_switch_inputtype(minirt, line[i]);
		if (j == 0)
			break ;
		i++;
	}
	if (j == 0)
	{
		ft_put_rtfile_error(line, i);
		ft_clear_minirt(minirt);
		ft_free_array(line);
		return (0);
	}
	ft_free_array(line);
	return (1);
}

int	ft_switch_inputtype(t_minirt *minirt, char *line)
{
	int	j;

	j = 0;
	if (line[0] == 'c' && ft_isspace(line[1]))
		j = ft_cam_input(&(minirt->firstcam), line);
	else if (line[0] == 'l')
		j = ft_light_input(&(minirt->firstlight), line);
	else if (line[0] == 'A')
		j = ft_amblight_input(&(minirt->al), line);
	else if (line[0] == 'R')
		j = ft_windowinfo_input(minirt, line);
	else
		j = ft_object_input(minirt, line);
	if (j == 0)
		return (0);
	return (1);
}

int	ft_check_input(t_minirt *minirt)
{
	if (minirt->width == -1 || minirt->hight == -1)
	{
		ft_put_resolution_error();
		ft_clear_minirt(minirt);
		return (0);
	}
	else if (minirt->al.flag == -1)
	{
		ft_put_ambient_error();
		ft_clear_minirt(minirt);
		return (0);
	}
	else if (minirt->firstcam == NULL)
	{
		ft_put_camera_error();
		ft_clear_minirt(minirt);
		return (0);
	}
	return (1);
}

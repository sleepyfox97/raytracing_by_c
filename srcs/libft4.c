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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*tmp1;
	char	*tmp2;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	tmp1 = s1;
	tmp2 = result;
	if (s1 != NULL)
	{
		while (*s1 != '\0')
			*tmp2++ = *s1++;
	}
	while (*s2 != '\0')
		*tmp2++ = *s2++;
	*tmp2 = '\0';
	free(tmp1);
	s1 = NULL;
	return (result);
}

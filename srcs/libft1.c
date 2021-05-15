#include "./miniRT.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atof(char *s, int i, double *result)
{
	double	j;
	double	minus;

	j = 1;
	minus = 1;
	i = ft_atol(s, i, result);
	if (s[i] == '.' && '0' <= s[i + 1] && s[i + 1] <= '9')
	{
		if (*result < 0)
		{
			minus = -1;
			if (*result == -1 && s[i - 1] == '0')
				*result = 0;
			else
				*result = *result * (-1);
		}
		i++;
		while ('0' <= s[i] && s[i] <= '9')
			*result = *result + ((s[i++]) - '0') * (j *= 0.1);
		*result = *result * minus;
	}
	if (*result == INFINITY || i == 0)
		return (0);
	return (i);
}

static int	ft_atol_sub(char *s, int i, double *result, double minus)
{
	if (*result > LONG_MAX / 10 && minus == 1)
		return (0);
	else if (*result == LONG_MAX / 10 && s[i] > '7' && minus == 1)
		return (0);
	else if (*result > LONG_MAX / 10 && minus == -1)
		return (0);
	else if (*result == LONG_MAX / 10 && s[i] > '8' && minus == -1)
		return (0);
	return (1);
}

int	ft_atol(char *s, int i, double *result)
{
	double	minus;

	minus = 1;
	*result = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		if (s[i++] == '-')
			minus = -1;
	if (s[i] == '0' && s[i + 1] == '0')
		return (0);
	while ('0' <= s[i] && s[i] <= '9')
	{
		if (!ft_atol_sub(s, i, result, minus))
			return (0);
		*result = ((s[i++]) - '0') + (*result) * 10;
	}
	*result = (*result) * minus;
	if (*result == 0 && minus == -1 && s[i] == '.')
		*result = -1;
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

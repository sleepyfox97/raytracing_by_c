#include "./miniRT.h"

int	isrtfile(char *s)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (slen < 4)
		return (0);
	if (s[slen - 1] == 't' && s[slen - 2] == 'r' && s[slen - 3] == '.')
		return (1);
	return (0);
}

int	issave(char *s)
{
	if (ft_strlen(s) != 6)
		return (0);
	if (s[0] == '-' && s[1] == '-' && s[2] == 's' && s[3] == 'a'
		&& s[4] == 'v' && s[5] == 'e')
		return (1);
	else
		return (0);
}

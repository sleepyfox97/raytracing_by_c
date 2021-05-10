#include "./miniRT.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned const char *)src;
	if (dst || src)
	{
		while (n-- > 0)
			*s1++ = *s2++;
		return (dst);
	}
	return (NULL);
}

int	ft_safe_free1(void *ptr)
{
	free (ptr);
	ptr = NULL;
	return (0);
}

t_cam	*ft_camlstlast(t_cam *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_light	*ft_lightlstlast(t_light *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_gob	*ft_oblstlast(t_gob *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

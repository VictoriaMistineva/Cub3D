#include "../cub.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *) s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char *) s++);
		s++;
	}
	return (NULL);
}

int	exiit(int key, t_all *all)
{
	exit(0);
	return (1);
}

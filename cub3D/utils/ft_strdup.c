#include "../cub.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		ln;

	ln = 0;
	while (s1[ln])
		ln++;
	copy = malloc((ln + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (copy - ln);
}

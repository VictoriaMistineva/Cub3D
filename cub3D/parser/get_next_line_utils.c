#include "../cub.h"

int	ft_strlen2(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_line(char *save)
{
	int	i;

	if (!save)
		return (-1);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	norme_gnl(char *remd, int i, int *j, char *new)
{
	while (remd[i + *j])
	{
		new[*j] = remd[i + *j];
		(*j)++;
	}
}

#include "../cub.h"

static char	*get_line(char *remd)
{
	int		i;
	char	*line;

	i = 0;
	while (remd && remd[i] && remd[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (remd && remd[i] && remd[i] != '\n')
	{
		line[i] = remd[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_strjoinplus(char *remd, char *buff, int ret)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc((ft_strlen2(remd) + ret + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (remd && remd[i])
	{
		new[i] = remd[i];
		i++;
	}
	j = 0;
	while (j < ret)
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	if (remd)
		free(remd);
	return (new);
}

static char	*free_remd(char *remd, int *ret, int j)
{
	char	*new;
	int		i;

	*ret = 0;
	i = is_line(remd);
	if (i < 0)
	{
		if (i == -1)
			free (remd);
		return (0);
	}
	new = (char *)malloc((ft_strlen2(remd) - i + 1) * sizeof(char));
	if (!new)
	{
		*ret = -1;
		free(remd);
		return (0);
	}
	i++;
	norme_gnl(remd, i, &j, new);
	new[j] = '\0';
	free(remd);
	return (new);
}

static int	get_next_l(int fd, char **line, unsigned int size)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remd[FOPEN_MAX];
	int			ret;

	if (read(fd, buff, 0) < 0)
		return (-1);
	*line = NULL;
	ret = 1;
	while (is_line(remd[fd]) < 0 && ret)
	{
		ret = read(fd, buff, size);
		remd[fd] = ft_strjoinplus(remd[fd], buff, ret);
		if (!remd[fd])
			return (-1);
	}
	*line = get_line(remd[fd]);
	if (!*line)
		return (-1);
	remd[fd] = free_remd(remd[fd], &ret, 0);
	if (!remd[fd])
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	unsigned int	size;

	if (BUFFER_SIZE <= 0 || !line || fd > FOPEN_MAX)
		return (-1);
	size = BUFFER_SIZE;
	size += 1;
	return (get_next_l(fd, line, size));
}

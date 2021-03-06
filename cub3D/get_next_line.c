/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:11:27 by ycordell          #+#    #+#             */
/*   Updated: 2021/03/05 13:16:23 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			len;

	if ((p = malloc(count * size)))
	{
		len = 0;
		while (len < size * count)
			p[len++] = 0;
		return (p);
	}
	return (0);
}

static char		*char_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char		*check_newline(char **line, char **remainder)
{
	char			*ptr_n;

	ptr_n = NULL;
	if (*remainder && **remainder)
	{
		if ((ptr_n = ft_strchr(*remainder, '\n')))
		{
			*ptr_n++ = '\0';
			*line = ft_substr(*remainder, 0, ft_strlen(*remainder));
			*remainder = ft_strcpy(*remainder, ptr_n);
		}
		else
		{
			*line = ft_substr(*remainder, 0, ft_strlen(*remainder));
			return (char_free(remainder));
		}
	}
	else
		*line = ft_calloc(1, sizeof(char));
	return (ptr_n);
}

static int		read_lines(t_gnl *gnl, char **remainder, int fd, char **line)
{
	int				count;

	count = 1;
	while ((!gnl->ptr_n && ((count = read(fd, gnl->buf, BUFFER_SIZE)) > 0)))
	{
		gnl->buf[count] = '\0';
		if ((gnl->ptr_n = ft_strchr(gnl->buf, '\n')))
		{
			*gnl->ptr_n++ = '\0';
			*remainder = ft_substr(gnl->ptr_n, 0, ft_strlen(gnl->ptr_n));
		}
		if (!(gnl->tmp = ft_strjoin(*line, gnl->buf)))
			return (-1);
		free(*line);
		*line = gnl->tmp;
	}
	if (count == -1)
		return (-1);
	gnl->count = count;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*remainder;
	t_gnl			gnl;
	register int	i;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		gnl.buf[i++] = '\0';
	gnl.ptr_n = check_newline(line, &remainder);
	if (read_lines(&gnl, &remainder, fd, line) == -1)
		return (-1);
	if (remainder && !*remainder)
		char_free(&remainder);
	if (!remainder && !gnl.count)
		return (0);
	return (1);
}

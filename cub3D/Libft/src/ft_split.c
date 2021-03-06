/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:42:07 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/27 18:01:41 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		charset(char const *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		if (*str != c)
		{
			while (*str != c && *str)
				str++;
			count++;
		}
	}
	return (count);
}

static char			*srtrim(char *s, char c)
{
	char *str;

	str = s;
	while (*str == c && *str)
		str++;
	return (str);
}

static size_t		lenw(char const *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char			**array_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	*str;
	char	**br;
	size_t	word;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s)
		return (NULL);
	str = (char *)s;
	word = charset(str, c);
	if (!(br = malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (++i < word)
	{
		str = srtrim(str, c);
		if (!(br[i] = malloc(sizeof(char) * (lenw(str, c) + 1))))
			array_free(br);
		j = 0;
		while (*str != c && *str != '\0')
			br[i][j++] = *str++;
		br[i][j] = '\0';
	}
	br[i] = NULL;
	return (br);
}

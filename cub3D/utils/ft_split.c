#include "../cub.h"

static size_t	charset(char const *s, char c)
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

static char	*srtrim(char *s, char c)
{
	char	*str;

	str = s;
	while (*str == c && *str)
		str++;
	return (str);
}

static size_t	lenw(char const *s, char c)
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

static char	**array_free(char **array)
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

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**br;
	size_t	word;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	str = (char *)s;
	word = charset(str, c);
	br = malloc(sizeof(char *) * (word + 1));
	if (!br)
		return (NULL);
	while (++i < word)
	{
		str = srtrim(str, c);
		br[i] = ft_strndup(str, lenw(str, c));
		if (!br[i])
			array_free(br);
		while (*str != c && *str != '\0')
			str++;
	}
	br[i] = NULL;
	return (br);
}

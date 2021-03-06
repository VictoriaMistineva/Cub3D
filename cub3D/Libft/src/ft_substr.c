/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 06:11:49 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/29 16:25:45 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*mall_str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	mall_str = malloc(len + 1);
	if (!mall_str)
		return (NULL);
	while (i < len)
	{
		mall_str[i] = s[i + start];
		i++;
	}
	mall_str[len] = '\0';
	return (mall_str);
}

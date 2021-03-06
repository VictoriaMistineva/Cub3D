/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:03:31 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 03:45:44 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char*)s++);
		s++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:18:37 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 04:28:30 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char*)s);
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (len--)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
	}
	return (NULL);
}

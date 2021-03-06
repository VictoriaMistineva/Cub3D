/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:57:02 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 19:13:12 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t a;
	size_t len;

	if (ft_strlen(dst) >= dstsize)
		len = ft_strlen(src) + dstsize;
	else
	{
		len = ft_strlen(dst) + ft_strlen(src);
		a = 0;
		i = 0;
		while (dst[i] != '\0')
			i++;
		if (dstsize != 0)
		{
			while (i + 1 < dstsize && src[a] != '\0')
				dst[i++] = src[a++];
			dst[i] = '\0';
		}
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:50:23 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 18:42:12 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char cd;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	cd = (unsigned char)c;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == cd)
			return (d);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:53:20 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 18:47:42 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char cd;

	str = (unsigned char *)s;
	cd = (unsigned char)c;
	while (n--)
	{
		if (*str == cd)
			return (str);
		str++;
	}
	return (NULL);
}

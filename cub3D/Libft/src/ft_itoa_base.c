/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:50:36 by ycordell          #+#    #+#             */
/*   Updated: 2021/04/09 14:50:37 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long number, int base, int is_upper_case, int *num_len)
{
	static char		buf[50];
	register int	len;
	char			c;
	char 			char_offset;

	char_offset = (is_upper_case) ? 55 : 87;
	len = ft_numlen((long)number, base);
	if (num_len)
		*num_len = len;
	buf[len--] = '\0';
	while (len >= 0)
	{
		c = (char)(number % base);
		buf[len--] = (char)(c + ((c > 9) ? char_offset : '0'));
		number /= base;
	}
	return buf;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:29:58 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 18:37:47 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n_len;
	size_t h_len;
	size_t spos;

	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	spos = 0;
	if (!n_len)
		return ((char *)haystack);
	if (len < h_len)
		h_len = len;
	if (n_len <= h_len)
		while (spos < (h_len - n_len + 1))
		{
			if (ft_memcmp(haystack + spos, needle, n_len) == 0)
				return ((char *)haystack + spos);
			spos++;
		}
	return (NULL);
}

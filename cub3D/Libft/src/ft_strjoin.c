/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:36:48 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 18:32:59 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *j;
	char *nach;

	if (!s1 || !s2)
		return (NULL);
	j = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!j)
		return (NULL);
	nach = j;
	while (*s1)
		*nach++ = *s1++;
	while (*s2)
		*nach++ = *s2++;
	*nach = '\0';
	return (j);
}

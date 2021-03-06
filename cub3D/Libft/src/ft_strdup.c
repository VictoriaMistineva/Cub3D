/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:48:53 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 18:38:43 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		ln;

	ln = 0;
	while (s1[ln])
		ln++;
	copy = malloc((ln + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (copy - ln);
}

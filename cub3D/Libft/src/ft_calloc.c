/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:03:28 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 19:15:33 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *i;

	i = (void *)malloc(count * size);
	if (!i)
		return (NULL);
	ft_bzero(i, count * size);
	return (i);
}

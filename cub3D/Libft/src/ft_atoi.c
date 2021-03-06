/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:57:33 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 19:11:31 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				a;
	unsigned int	i;

	i = 0;
	a = 1;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
	{
		a = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * a);
}

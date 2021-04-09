/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:50:20 by ycordell          #+#    #+#             */
/*   Updated: 2021/04/09 14:50:21 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numlen(long number, int base)
{
	int		len;

	if (number == 0)
		return (1);
	len = (number < 0) ? 2 : 1;
	while (number /= base)
		len++;
	return (len);
}

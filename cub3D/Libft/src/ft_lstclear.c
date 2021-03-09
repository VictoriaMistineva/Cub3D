/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:41:06 by jkeitha           #+#    #+#             */
/*   Updated: 2021/03/09 16:31:31 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*in;

	in = *lst;
	if (!in)
		return ;
	while (in)
	{
		tmp = in->next;
		del(in->content);
		free(in);
		in = tmp;
	}
	*lst = 0;
}

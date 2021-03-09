/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:07:08 by jkeitha           #+#    #+#             */
/*   Updated: 2021/03/09 16:32:08 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstn;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	lstn = 0;
	while (lst)
	{
		if (!(temp = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lstn, del);
			return (0);
		}
		ft_lstadd_back(&lstn, temp);
		lst = lst->next;
	}
	return (lstn);
}

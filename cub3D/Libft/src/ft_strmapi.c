/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:01:21 by ycordell          #+#    #+#             */
/*   Updated: 2020/11/25 19:14:17 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapi;

	i = 0;
	if (!s || !f)
		return (NULL);
	mapi = (char *)malloc(ft_strlen(s) + 1);
	if (!mapi)
		return (NULL);
	while (s[i])
	{
		mapi[i] = s[i];
		i++;
	}
	mapi[i] = '\0';
	i = 0;
	while (mapi[i])
	{
		mapi[i] = f(i, mapi[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

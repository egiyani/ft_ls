/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:27:51 by egiyani           #+#    #+#             */
/*   Updated: 2018/06/11 09:44:28 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;

	if (lst && f)
	{
		nlst = f(lst);
		if (nlst && lst->next)
			nlst->next = ft_lstmap(lst->next, f);
		return (nlst);
	}
	return (NULL);
}

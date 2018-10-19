/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:14:34 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/04 10:14:41 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_one;

	new_one = ft_list_create_elem(data);
	new_one->next = *begin_list;
	*begin_list = new_one;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:20:13 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:20:15 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list		*this_one;
	t_list		*next_one;
	t_list		*last;

	this_one = *begin_list;
	last = NULL;
	while (this_one != NULL)
	{
		next_one = this_one->next;
		this_one->next = last;
		last = this_one;
		this_one = next_one;
	}
	*begin_list = last;
}

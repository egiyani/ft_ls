/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:20:59 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:21:01 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_sort(t_list **first, int (*compare)(void*, void*))
{
	int		changed;
	t_list	*current;

	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *first;
		while (current->next)
		{
			if (compare(current->data, current->next->data) > 0)
			{
				ft_ptrswp(&current->data, &current->next->data);
				changed = 1;
			}
			current = current->next;
		}
	}
}

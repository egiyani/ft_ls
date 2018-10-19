/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:19:45 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:19:48 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_list_remove_node(t_list **original
											, t_list *to_remove
											, void (*free_inside)(void*))
{
	t_list				*old_one;

	if (original && *original && to_remove)
	{
		if (*original == to_remove)
		{
			old_one = *original;
			*original = (*original)->next;
			if (free_inside)
				free_inside(old_one->data);
		}
		else
			ft_list_remove_node(&((*original)->next), to_remove, free_inside);
	}
}

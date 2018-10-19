/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:18:23 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:18:26 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		destroy_list(t_list *list, void (*free_inside)())
{
	if (list->next != NULL)
		destroy_list(list->next, free_inside);
	if (free_inside)
		free_inside(list->data);
	free(list);
}

void			ft_list_clear(t_list **begin_list, void (*free_inside)())
{
	destroy_list(*begin_list, free_inside);
	*begin_list = NULL;
}

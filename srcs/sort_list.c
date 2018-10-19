/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:55:41 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:43:40 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int			ft_strcmp_wrapper(void *first, void *second)
{
	int				i;

	i = ft_strcmp(((t_entry*)first)->short_name
					, ((t_entry*)second)->short_name);
	return (i);
}

static int			compare_time_wrapper(void *first
											, void *second)
{
	int		c;

	c = compare_last_modified_time(lstat_if_sym((t_entry*)first)
								, lstat_if_sym((t_entry*)second));
	if (c == 0)
		return (ft_strcmp_wrapper(first, second));
	else
		return (c);
}

void				sort_list_entries(t_list **list, t_options *options)
{
	if (options->sort_time_md)
		ft_list_sort(list, &compare_time_wrapper);
	else
		ft_list_sort(list, &ft_strcmp_wrapper);
	if (options->reverse_sort)
		ft_list_reverse(list);
}

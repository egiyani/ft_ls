/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:33:32 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 10:35:45 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_total_block_size(t_list *entries)
{
	unsigned long long	total;
	char				*str;

	total = 0;
	while (entries)
	{
		total += lstat_if_sym(((t_entry*)entries->data))->st_blocks;
		entries = entries->next;
	}
	ft_putstr("total ");
	str = ft_itoa_ularge(total);
	ft_putstr(str);
	free(str);
	ft_putchar('\n');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:13:01 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:35:07 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool				should_print_entry(t_entry *entry, t_options *options)
{
	t_bool			bleh;

	bleh = *entry->short_name != '.'
		|| options->show_all
		|| options->error_handler2;
	return (bleh);
}

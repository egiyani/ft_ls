/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:12:20 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:34:04 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			arrow(t_entry *entry)
{
	char			buffer[LINK_BUFSIZE];

	if (entry->is_symlink)
	{
		ft_putstr("->");
		write(1, buffer, readlink(entry->long_name, buffer, LINK_BUFSIZE));
	}
}

void				print_entry(t_entry *entry, t_options *options
								, t_strlens *strlens)
{
	if (options->long_format)
	{
		print_file_options(entry, strlens);
		ft_putchar(' ');
		ft_putstr(entry->short_name);
		arrow(entry);
		ft_putchar('\n');
	}
	else
		ft_putendl(entry->short_name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:52:29 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:39:37 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_time(t_entry *entry)
{
	char			*str;
	time_t			stat_time;
	time_t			diff;

	stat_time = lstat_if_sym(entry)->st_mtimespec.tv_sec;
	str = ft_strdup(ctime(&stat_time));
	write(1, str + 4, 7);
	diff = entry->time_generated - stat_time;
	if (diff > SIX_MONTHS_SECONDS || diff < -SIX_MONTHS_SECONDS)
		write(1, str + 19, 5);
	free(str);
}

static void			print_file_size(t_entry *entry, t_strlens *strlens)
{
	if (entry->first_file_size_string)
	{
		ft_putstr_justify_right(entry->first_file_size_string
									, strlens->major + 3, ' ');
		ft_putstr(",");
		ft_putstr_justify_right(entry->second_file_size_string
								, strlens->file_size - strlens->major - 1, ' ');
	}
	else
	{
		ft_putstr_justify_right(entry->second_file_size_string
								, strlens->file_size + (strlens->major ? 4 : 2)
								, ' ');
	}
}

void				print_file_options(t_entry *entry, t_strlens *strlens)
{
	ft_putchar(entry->file_type_char);
	print_file_permissions(entry);
	ft_putnbr_justify_right(lstat_if_sym(entry)->st_nlink
							, strlens->nlink + 1, ' ');
	ft_putstr(" ");
	ft_putstr_justify_left(entry->username, strlens->username + 2, ' ');
	ft_putstr_justify_left(entry->group_name, strlens->group_name, ' ');
	print_file_size(entry, strlens);
	ft_putstr(" ");
	print_time(entry);
}

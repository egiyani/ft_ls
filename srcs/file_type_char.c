/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:08:46 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/03 11:09:07 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				get_file_type_char(t_entry *entry)
{
	if (entry->is_symlink)
		return ('l');
	if (S_ISBLK(entry->stat->st_mode))
		return ('b');
	else if (entry->stat->st_mode & S_IFCHR)
		return ('c');
	else if (S_ISSOCK(entry->stat->st_mode))
		return ('s');
	else if (entry->stat->st_mode & S_IFIFO)
		return ('p');
	else if (entry->stat->st_mode & S_IFDIR)
		return ('d');
	return ('-');
}

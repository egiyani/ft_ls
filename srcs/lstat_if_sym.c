/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat_if_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:07:40 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/03 11:08:13 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat				*lstat_if_sym(t_entry *entry)
{
	if (entry->is_symlink)
		return (entry->lstat);
	else
		return (entry->stat);
}

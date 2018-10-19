/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_folder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:11:27 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:42:00 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					name_begins_with_dot(char *long_name)
{
	char			*folder;

	folder = ft_strchr(long_name, '\0');
	while (folder > long_name && *(folder - 1) != '/')
		folder--;
	return (*folder == '.');
}

int					should_print_folder(char *long_name
											, t_options *options)
{
	if (options->recursive_handler && !options->show_all)
		return (!name_begins_with_dot(long_name));
	return (1);
}

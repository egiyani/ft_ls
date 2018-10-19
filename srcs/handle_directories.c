/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:45:51 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:29:12 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_folder_name(char *folder_name
										, t_options *options)
{
	if (options->already_printed_folder)
		ft_putstr("\n");
	ft_putstr(folder_name);
	ft_putstr(":\n");
	options->already_printed_folder = 1;
}

void				handle_directories(t_list *folder_name
									, t_list *directory
									, t_options *options)
{
	char			*str;
	t_bool			printed_folder;

	while (folder_name)
	{
		str = (char*)folder_name->data;
		printed_folder = should_print_folder(str, options);
		if (options->print_folder_names_before && printed_folder)
			print_folder_name(str, options);
		if (directory->data)
			handle_directory(str, (t_list*)directory->data, printed_folder
							, options);
		folder_name = folder_name->next;
		directory = directory->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:05:46 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 09:41:13 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			handle_recursive(t_list **entries, t_options *options)
{
	int				hrb;

	options->print_folder_names_before = 1;
	hrb = options->recursive_handler;
	handle_ls(entries, options);
	options->recursive_handler = hrb;
}

static t_bool		link_points_to_itself(t_entry *entry)
{
	char			*link;

	if (entry->is_symlink)
	{
		link = get_readlink_string(entry->long_name);
		if (ft_strequ(link, "./") || ft_strequ(link, "."))
			return (1);
	}
	return (0);
}

static void			print_recursives(t_list *entries
										, t_options *options)
{
	t_list		*r;
	t_entry		*entry;

	r = NULL;
	while (entries)
	{
		entry = (t_entry*)entries->data;
		if (entry->stat->st_mode & S_IFDIR
				&& !ft_strequ(entry->short_name, ".")
				&& !ft_strequ(entry->short_name, "..")
				&& !link_points_to_itself(entry))
			ft_list_push_front(&r, entry->long_name);
		entries = entries->next;
	}
	if (r)
		handle_recursive(&r, options);
}

void				handle_directory(char *folder_name, t_list *directory
										, t_bool print_folder
										, t_options *options)
{
	t_list			*entries;
	t_entry			*entry;

	entries = NULL;
	while (directory && (entry = make_entry(folder_name
										, ft_strdup((char*)directory->data)
								, options)))
	{
		ft_list_push_front(&entries, entry);
		directory = directory->next;
	}
	if (entries)
	{
		sort_list_entries(&entries, options);
		if (print_folder)
			print_entries(entries, options);
		if (options->recursive_folders)
			print_recursives(entries, options);
	}
}

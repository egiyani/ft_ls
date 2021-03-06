/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_handlerrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:56:52 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 09:24:22 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_screw_ups(t_list *screw_ups, t_list **arguments
									, t_options *options)
{
	t_list			*entries;

	entries = NULL;
	while (screw_ups)
	{
		ft_list_push_front(&entries
							, make_entry("./", (char*)screw_ups->data
											, options));
		ft_list_remove_if(arguments, screw_ups->data, &ft_ptrequ);
		screw_ups = screw_ups->next;
	}
	options->error_handler2 = 1;
	sort_list_entries(&entries, options);
	print_entries(entries, options);
	options->error_handler2 = 0;
}

static void			do_screw_ups_and_handling(t_list **arguments
												, t_list **directory_list
												, t_list **screw_ups
												, t_options *options)
{
	if (options->reverse_sort)
	{
		ft_list_reverse(arguments);
		ft_list_reverse(directory_list);
		ft_list_reverse(screw_ups);
	}
	if (*screw_ups && options->error_handler)
	{
		print_screw_ups(*screw_ups, arguments, options);
		ft_list_clear(screw_ups, NULL);
		options->print_folder_names_before = 1;
	}
	options->error_handler = 0;
	if (directory_list)
		handle_directories(*arguments, *directory_list, options);
}

static t_bool		should_treat_link_as_screw_up(char *name
													, t_list **arguments
													, t_list *this_argument
													, t_options *options)
{
	t_stat			statistics;
	DIR				*opened;

	if (*(ft_strchr(name, '\0') - 1) == '/')
		return (0);
	if (lstat(name, &statistics))
		ft_list_remove_node(arguments, this_argument, NULL);
	else if (S_ISLNK(statistics.st_mode))
	{
		opened = opendir(name);
		if (opened)
		{
			closedir(opened);
			return (options->long_format);
		}
		return (1);
	}
	return (0);
}

static void			setup(t_list **directory_list, t_list **screw_ups
							, t_list **arguments, t_list **this_arg)
{
	ft_list_sort(arguments, (int (*)(void*, void*))&ft_strcmp);
	*directory_list = NULL;
	*screw_ups = NULL;
	*this_arg = *arguments;
}

void				handle_ls(t_list **arguments, t_options *options)
{
	t_list		*directory_list;
	t_list		*this_arg;
	t_list		*screw_ups;
	char		*folder_name;

	setup(&directory_list, &screw_ups, arguments, &this_arg);
	while (this_arg)
	{
		folder_name = (char*)this_arg->data;
		if (options->error_handler
			&& should_treat_link_as_screw_up(folder_name, arguments
												, this_arg, options))
			ft_list_push_back(&screw_ups, folder_name);
		else
			read_through_directory(folder_name, &directory_list, &screw_ups);
		this_arg = this_arg->next;
	}
	do_screw_ups_and_handling(arguments, &directory_list, &screw_ups, options);
}

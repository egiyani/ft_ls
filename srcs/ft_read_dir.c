/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:37:27 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:41:12 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*read_dir(DIR *opened)
{
	t_list			*names;
	struct dirent	*read;

	if (!opened)
		return (NULL);
	names = NULL;
	while ((read = readdir(opened)))
		ft_list_push_front(&names, ft_strdup(read->d_name));
	return (names);
}

void				read_through_directory(char *folder_name
											, t_list **directory_list
											, t_list **error)
{
	DIR				*opened;

	opened = opendir(folder_name);
	ft_list_push_back(directory_list, read_dir(opened));
	if (opened)
		closedir(opened);
	else
		directory_open_failed(folder_name, error);
}

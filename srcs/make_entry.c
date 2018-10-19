/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:51:47 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 12:29:53 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool				set_stats(t_entry *entry)
{
	entry->lstat = malloc(sizeof(t_stat));
	if (lstat(entry->long_name, entry->lstat))
	{
		perror(entry->long_name);
		free(entry->lstat);
		return (1);
	}
	entry->stat = malloc(sizeof(t_stat));
	if (stat(entry->long_name, entry->stat))
		entry->stat = entry->lstat;
	entry->is_symlink = S_ISLNK(entry->lstat->st_mode);
	entry->time_generated = time(NULL);
	return (0);
}

char				*get_long_name(char *original, char *short_name)
{
	char			*with_slash;
	char			*long_name;

	if (*short_name == '/')
		return (ft_strdup(short_name));
	if (original[ft_strlen(original) - 1] == '/')
		long_name = ft_strjoin(original, short_name);
	else
	{
		with_slash = ft_strjoin(original, "/");
		long_name = ft_strjoin(with_slash, short_name);
		free(with_slash);
	}
	return (long_name);
}

t_entry				*make_entry(char *folder, char *short_name
								, t_options *options)
{
	t_entry			*new;

	new = malloc(sizeof(t_entry));
	ft_bzero(new, sizeof(t_entry));
	new->short_name = short_name;
	new->long_name = get_long_name(folder, new->short_name);
	if ((options->recursive_folders
			|| options->sort_time_md
			|| options->long_format)
		&& set_stats(new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

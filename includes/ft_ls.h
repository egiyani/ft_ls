/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:51:19 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 10:55:39 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <pwd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <grp.h>
# include <errno.h>
# include "libft.h"

# define LINK_BUFSIZE				256
# define SIX_MONTHS_SECONDS			15778500

typedef char			t_bool;
typedef struct stat		t_stat;

typedef struct			s_options
{
	t_bool		sort_time_md;
	t_bool		show_all;
	t_bool		long_format;
	t_bool		reverse_sort;
	t_bool		print_folder_names_before;
	t_bool		already_printed_folder;
	t_bool		error_handler;
	t_bool		error_handler2;
	t_bool		recursive_folders;
	t_bool		recursive_handler;
	t_bool		one_per_line;
}						t_options;

typedef	struct			s_entry
{
	time_t		time_generated;
	int			is_symlink;
	char		file_type_char;
	char		*group_name;
	char		*username;
	char		*first_file_size_string;
	char		*second_file_size_string;
	char		*short_name;
	char		*long_name;
	t_stat		*stat;
	t_stat		*lstat;

}						t_entry;

typedef struct			s_strlens
{
	int			major;
	int			nlink;
	int			file_size;
	uintmax_t	username;
	uintmax_t	group_name;
}						t_strlens;

void					print_total_block_size(t_list *entries);
void					directory_open_failed(char *failing_name
											, t_list **screw_ups);
void					print_file_options(t_entry *entry, t_strlens *strlens);
char					first_executable_permissions(mode_t mode);
void					print_file_permissions(t_entry *entry);
char					get_file_type_char(t_entry *entry);
void					free_entry(t_entry *entry);
void					handle_ls(t_list **arguments, t_options *options);
void					prepare_file_options(t_strlens *strlens
											, t_list *entries
											, t_options *options);
void					read_through_directory(char *folder_name
											, t_list **directory_list
											, t_list **error);
void					handle_directory(char *folder_name, t_list *directory
										, t_bool print_folder
										, t_options *options);
void					handle_directories(t_list *folder_name
									, t_list *directory
									, t_options *options);
t_stat					*lstat_if_sym(t_entry *entry);
t_bool					set_stats(t_entry *entry);
char					*get_long_name(char *original, char *short_name);
t_entry					*make_entry(char *folder, char *short_name
								, t_options *options);
int						compare_last_modified_time(struct stat *first
												, struct stat *second);
void					print_entries(t_list *entries, t_options *options);
void					print_entry(t_entry *entry, t_options *options
								, t_strlens *strlens);
int						name_begins_with_dot(char *long_name);
int						should_print_folder(char *long_name
											, t_options *options);
char					*get_readlink_string(char *link_path);
t_bool					should_print_entry(t_entry *entry, t_options *options);
void					sort_list_entries(t_list **list, t_options *options);

#endif

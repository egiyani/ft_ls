/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:09:13 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/13 17:16:33 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			check_for_empty_argument(char *argument)
{
	if (argument[0] == '\0')
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		exit(1);
	}
}

static void			set_option(char c, t_options *options)
{
	if (c == 'l')
		options->long_format = 1;
	else if (c == 'R')
		options->recursive_folders = 1;
	else if (c == 'a')
		options->show_all = 1;
	else if (c == 'r')
		options->reverse_sort = 1;
	else if (c == 't')
		options->sort_time_md = 1;
	else if (c == '1')
	{
		options->one_per_line = 1;
		options->long_format = 0;
	}
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
		exit(1);
	}
}

static void			parse_options(char *string, t_options *options)
{
	while (*string)
	{
		set_option(*string, options);
		string++;
	}
}

static void			proceed_with_main(t_list **arguments, t_options *options)
{
	char			*src;

	src = ft_strdup("./");
	if (!*arguments)
		ft_list_push_front(arguments, src);
	options->print_folder_names_before = ft_list_size(*arguments) > 1;
	options->error_handler = 1;
	handle_ls(arguments, options);
	free(src);
}

int					main(int argc, char **argv)
{
	int				i;
	t_list			*arguments;
	t_options		options;

	ft_bzero(&options, sizeof(t_options));
	arguments = NULL;
	i = 1;
	while (i < argc && argv[i][0] != '\0' && argv[i][0] == '-'
			&& argv[i][1] != '\0' && !ft_strequ(argv[i], "--"))
	{
		parse_options(argv[i] + 1, &options);
		i++;
	}
	if (i < argc && ft_strequ(argv[i], "--"))
		i++;
	while (i < argc)
	{
		check_for_empty_argument(argv[i]);
		ft_list_push_front(&arguments, argv[i]);
		i++;
	}
	proceed_with_main(&arguments, &options);
	free(arguments);
	return (0);
}

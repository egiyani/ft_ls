/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:06:21 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/03 11:07:00 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					compare_last_modified_time(struct stat *first
												, struct stat *second)
{
	return (second->st_mtimespec.tv_sec - first->st_mtimespec.tv_sec);
}

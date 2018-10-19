/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:38:34 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/10 10:33:22 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*get_readlink_string(char *link_path)
{
	char			buffer[LINK_BUFSIZE];
	size_t			lu;

	lu = readlink(link_path, buffer, LINK_BUFSIZE);
	if (lu >= LINK_BUFSIZE)
		ft_putendl_exit("Link filename too long\n", 1);
	buffer[lu] = '\0';
	return (ft_strdup(buffer));
}

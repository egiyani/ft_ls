/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_justify_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:15:08 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/04 10:15:29 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_justify_right(int number
											, size_t total
											, char fill)
{
	char			*string;

	string = ft_itoa(number);
	ft_putstr_justify_right(string, total, fill);
	free(string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:33:14 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:33:21 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ptrswp(void **first, void **second)
{
	void		*temporary;

	temporary = *second;
	*second = *first;
	*first = temporary;
}

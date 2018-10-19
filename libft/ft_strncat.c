/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:35:21 by egiyani           #+#    #+#             */
/*   Updated: 2018/05/25 12:15:40 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src != '\0' && n--)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:17:26 by egiyani           #+#    #+#             */
/*   Updated: 2018/05/29 14:33:47 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	size_t			i;

	i = 0;
	ndst = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	while (i < n)
	{
		*ndst++ = *nsrc;
		if (*nsrc++ == (unsigned char)c)
		{
			return (ndst);
		}
		i++;
	}
	return (NULL);
}

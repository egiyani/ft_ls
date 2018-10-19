/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:37:54 by egiyani           #+#    #+#             */
/*   Updated: 2018/06/01 17:41:09 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*s;
	size_t	i;

	dst = (char *)dest;
	s = (char *)src;
	i = 0;
	if (s < dst)
	{
		while (n--)
			dst[n] = s[n];
	}
	else
		ft_memcpy(dst, s, n);
	return (dst);
}

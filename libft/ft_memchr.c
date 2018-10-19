/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:58:12 by egiyani           #+#    #+#             */
/*   Updated: 2018/05/24 15:57:42 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

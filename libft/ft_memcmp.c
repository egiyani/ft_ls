/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:44:22 by egiyani           #+#    #+#             */
/*   Updated: 2018/05/23 09:13:33 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char		*s1;
	const unsigned char		*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (str1 == str2 || n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n != '\0')
		{
			s1++;
			s2++;
		}
	}
	return (0);
}

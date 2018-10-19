/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:57:45 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/05 10:58:15 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr_last(const char *haystack, int needle)
{
	char			*end;

	end = ft_strchr(haystack, '\0');
	while (end >= haystack)
	{
		if (*end == needle)
			return ((char*)end);
		end--;
	}
	return (NULL);
}

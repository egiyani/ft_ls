/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:48:20 by egiyani           #+#    #+#             */
/*   Updated: 2018/09/13 17:04:23 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char			*temp;
	unsigned long	len;
	unsigned long	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(temp = (char*)malloc(len + 1)))
		return (NULL);
	i = len;
	len = 0;
	while (len < i)
	{
		temp[len] = src[len];
		len++;
	}
	temp[len] = '\0';
	return (temp);
}

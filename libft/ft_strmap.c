/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:29:23 by egiyani           #+#    #+#             */
/*   Updated: 2018/05/31 09:37:19 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*nbr;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	nbr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (nbr == 0)
		return (0);
	while (s[i] != '\0')
	{
		nbr[i] = f(s[i]);
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}

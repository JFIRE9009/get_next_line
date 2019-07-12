/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:50:24 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/12 07:48:27 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c, bool b)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if ((s[i] != c || b == 1) && s[i])
		j++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] && b == 0)
				i++;
			if (s[i] && b == 1)
				i++;
			if (s[i])
				j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	}
	return (j);
}

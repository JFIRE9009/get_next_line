/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:51:35 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/12 08:13:37 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcreturn(char const *s, char c, size_t x, bool b)
{
	char	*ns;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ns = NULL;
	if (s[i] != c || b == 1)
		j++;
	while (s[i] && j <= x)
		if (s[i] == c && s[i])
		{
			while (s[i] == c && s[i] && b == 0)
				i++;
			if (s[i] && b == 1)
				i++;
			j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	if (s[i])
		ns = ft_strsub(s, i, ft_strcnlen(s, c, x, b));
	return (ns);
}

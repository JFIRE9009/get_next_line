/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:40:26 by sconstab          #+#    #+#             */
/*   Updated: 2019/05/27 13:56:19 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t n;

	i = 0;
	n = ft_strlen(s) + 1;
	if (s[i] != c)
	{
		i++;
		if (i == n)
			return (NULL);
		else
			return (ft_strchr(s + i, c));
	}
	return ((char *)s + i);
}

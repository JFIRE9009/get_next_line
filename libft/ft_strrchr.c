/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:23:04 by sconstab          #+#    #+#             */
/*   Updated: 2019/05/27 13:56:22 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s);
	if (c == 0)
		return ((char *)s + n);
	while (n > 0)
	{
		n--;
		if (s[n] == c)
			return ((char *)s + n);
	}
	return (NULL);
}

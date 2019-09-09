/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:42:01 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/19 18:15:17 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 1;
	len = ft_intlen(n);
	if (!(s = malloc(len + 2 * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		j = -1;
		s[--len] = '-';
	}
	if (n == 0)
		return ("0");
	while (i < len)
	{
		s[i++] = j * (n % 10) + '0';
		n = n / 10;
	}
	s[i + 1] = '\0';
	return (ft_strrev(s));
}

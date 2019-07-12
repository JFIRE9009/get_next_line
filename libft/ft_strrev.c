/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:51:06 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/12 06:32:56 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	ft_putnbr(len = ft_strlen(s));
	str = ft_strnew(len);
	while (s[len] != '\0')
	{
		s[i] = s[len];
		*str = s[i];
		i++;
		len--;
	}
	ft_putstr(str);
	return (str);
}

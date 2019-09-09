/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 07:46:12 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/19 18:03:02 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*ns;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) - 1;
	ns = ft_strnew(len);
	while (len >= 0)
		ns[i++] = s[len--];
	ns[i] = '\0';
	return (ns);
}

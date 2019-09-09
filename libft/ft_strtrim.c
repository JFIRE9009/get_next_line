/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:44:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/06 14:01:22 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	e;
	size_t	it;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	e = ft_strlen(s);
	while (i < e && (s[e - 1] == ' ' || s[e - 1] == '\n' || s[e - 1] == '\t'))
		e--;
	if (e == i)
		return (ft_strnew(1));
	it = e - i;
	return (ft_strsub(s, i, it));
}

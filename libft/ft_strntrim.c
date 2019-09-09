/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:55:30 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/06 14:00:44 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strntrim(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	it;
	char	*ns;

	i = 0;
	j = 0;
	it = ft_strlen(s) - 1;
	ns = ft_strnew(it + 1);
	if (s == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[it] == c)
		it--;
	it++;
	while (i < it && s[i])
		ns[j++] = s[i++];
	return (ns);
}

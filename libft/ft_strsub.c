/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:17:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/05 09:33:16 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ns;

	if (!s)
		return (NULL);
	if (!(ns = malloc(len + 1 * sizeof(char))))
		return (NULL);
	ft_strncpy(ns, s + start, len);
	ns[len] = '\0';
	return (ns);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:36:24 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/04 15:46:51 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	if (src == NULL && dst == NULL)
		return (NULL);
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}

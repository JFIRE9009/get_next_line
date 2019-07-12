/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:05:56 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/12 08:22:20 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(str, s1);
	free((char *)s1);
	ft_strcat(str, s2);
	free((char *)s2);
	return (str);
}

char		*ft_readfile(const int fd)
{
	char *file;
	char *buff;

	file = ft_strnew(0);
	buff = ft_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		file = ft_strjoin_free(file, buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	free(buff);
	return (file);
}

int			get_next_line(const int fd, char **line)
{
	static void		*red;
	static size_t	i;

	if (fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (red == NULL)
		red = ft_readfile(fd);
	while (i < (ft_wordcount(red, '\n', 1)))
	{
		*line = ft_strcreturn(red, '\n', i, 1);
		i++;
		return (1);
	}
	free(red);
	return (0);
}

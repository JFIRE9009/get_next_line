/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:13:09 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/15 15:57:20 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char		*get_line(char **line, char *lines)
{
	char	*temp;
	int		i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
		i++;
	*line = ft_strsub(lines, 0, i);
	if (ft_strcmp(*line, lines) == 0)
		return (NULL);
	else
	{
		temp = ft_strsub(lines, i + 1, (ft_strlen(lines + i) + 1));
		free(lines);
	}
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[1024];
	int			amnt_read;

	amnt_read = 0;
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	if (!(ft_strchr(str[fd], '\n')))
	{
		while ((amnt_read = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[amnt_read] = '\0';
			str[fd] = ft_strjoin_free(str[fd], buff);
			if (ft_strchr(str[fd], '\n'))
				break ;
		}
	}
	if (amnt_read == 0 && !ft_strlen(str[fd]))
		return (0);
	str[fd] = get_line(line, str[fd]);
	return (1);
}

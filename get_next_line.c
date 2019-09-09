/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 06:56:45 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/02 10:12:06 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_line(const int fd, char **stored)
{
	int			res;
	char		*buff;
	char		*temp;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	res = read(fd, buff, BUFF_SIZE);
	if (res > 0)
	{
		buff[res] = '\0';
		if (!(temp = ft_strjoin(*stored, buff)))
			return (-1);
		free(*stored);
		free(buff);
		*stored = temp;
	}
	if (res == 0)
		free(buff);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	int			value;
	static char	*str[1024];
	char		*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	tmp = ft_strchr(str[fd], '\n');
	while (!tmp)
	{
		value = read_line(fd, &str[fd]);
		if (value == 0 && !ft_strlen(str[fd]))
			return (0);
		if (value == 0)
			ft_strcat(str[fd], "\n");
		if (value < 0)
			return (-1);
		else
			tmp = ft_strchr(str[fd], '\n');
	}
	if (!(*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]) - ft_strlen(tmp))))
		return (-1);
	ft_strcpy(str[fd], tmp + 1);
	return (1);
}

#include <fcntl.h>

int	main(int argc, char **argv)
{
	char *line;
	char *tmp;
	int fd;

	if (argc == 1)
		fd = open("get_next_line.c", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		{
			tmp = line;
			ft_putendl(tmp);
			free(tmp);
		}
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:30:08 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 20:35:09 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static void	ft_strclr(char *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

static int	ft_get_rest(char **line, char **rest)
{
	char	*tmp_rest;

	if (*rest)
	{
		if ((tmp_rest = ft_strchr(*rest, '\n')))
		{
			*tmp_rest++ = '\0';
			if (!(*line = ft_strdup(*rest)))
				return (-1);
			!tmp_rest ? ft_strdel(&(*rest)) : ft_strcpy(*rest, tmp_rest);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(*rest)))
				return (-1);
			ft_strdel(&(*rest));
			return (0);
		}
	}
	else if (!(*line = ft_strdup("")))
		return (-1);
	return (0);
}

static int	ft_get_line(char *buf, char **rest, int fd, char **line)
{
	size_t	ret;
	char	*ptr_rest;
	char	*tmp_line;

	ptr_rest = NULL;
	while (!ptr_rest && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if ((ptr_rest = ft_strchr(buf, '\n')))
		{
			*ptr_rest++ = '\0';
			if (ptr_rest)
				*rest = ft_strdup(ptr_rest);
		}
		tmp_line = *line;
		if (!(*line = ft_strjoin(*line, buf)) || ret < 0)
			return (-1);
		ft_strclr(tmp_line);
	}
	ft_strclr(buf);
	if (ret == 0)
		ft_strdel(&(*rest));
	return ((ret == 0) ? 0 : 1);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[REST_SIZE];
	char		*buf;
	int			res;

	if (fd < 0 || fd > REST_SIZE || !line || BUFFER_SIZE <= 0 ||
		!(buf = (char *)malloc(BUFFER_SIZE + 1)) || (read(fd, rest, 0) < 0))
		return (-1);
	*line = NULL;
	if ((res = ft_get_rest(line, &rest[fd])) != 0)
	{
		ft_strclr(buf);
		return (res);
	}
	return (ft_get_line(buf, &rest[fd], fd, line));
}

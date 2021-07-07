/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:45:13 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:07:54 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Парсит параметры SPRITE PATH. Дублирует путь
**							к нужной текстуре и записывает его в t_cub *cub.
**
** Возвращаемое значение:	(int) '0'	-	Произошел парсинг.
** 							(int) '-1'	-	Произошла ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке:
**							--> DOUBLE DECLARATION OF [SPRITE PATH]
**							--> MALLOC ERROR IN [SPRITE PATH]
**							--> TOO MANY PARAM IN [SPRITE PATH]
**
** Особенности:				Нет.
*/

static int	ft_check_double_declartion(char *cmp_line, t_cub *cub)
{
	int	res;

	res = 0;
	if (!(ft_strncmp(cmp_line, "NO", 2)) && cub->path.no != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [SPRITE PATH - NO]\n", 2);
	else if (!(ft_strncmp(cmp_line, "SO", 2)) && cub->path.so != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [SPRITE PATH - SO]\n", 2);
	else if (!(ft_strncmp(cmp_line, "WE", 2)) && cub->path.we != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [SPRITE PATH - WE]\n", 2);
	else if (!(ft_strncmp(cmp_line, "EA", 2)) && cub->path.ea != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [SPRITE PATH - EA]\n", 2);
	else if (!(ft_strncmp(cmp_line, "S ", 2)) && cub->path.spr != NULL)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [SPRITE PATH - SP]\n", 2);
	return (res);
}

int			ft_parse_cub_sprite(char **line, t_cub *cub, char *cmp_line)
{
	char	*tmp_line;

	*line += 2;
	ft_move_spaces(line);
	if (ft_check_double_declartion(cmp_line, cub) == -1)
		return (-1);
	if (!(tmp_line = ft_strdup(*line)))
		return (ft_putstr_fd("--> MALLOC ERROR IN [SPRITE PATH]\n", 2));
	if (!(ft_strncmp(cmp_line, "NO", 2)))
		cub->path.no = tmp_line;
	else if (!(ft_strncmp(cmp_line, "SO", 2)))
		cub->path.so = tmp_line;
	else if (!(ft_strncmp(cmp_line, "WE", 2)))
		cub->path.we = tmp_line;
	else if (!(ft_strncmp(cmp_line, "EA", 2)))
		cub->path.ea = tmp_line;
	else if (!(ft_strncmp(cmp_line, "S ", 2)))
		cub->path.spr = tmp_line;
	ft_move_non_spaces(line);
	ft_move_spaces(line);
	if (**line != '\0')
		return (ft_putstr_fd("--> TOO MANY PARAM IN [SPRITE PATH]\n", 2));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:24:07 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:08:16 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Определяет что нужно парсить и парсит в структуру.
**
** Возвращаемое значение:	(int) '0'	-	Произошел парсинг
**											или пропущена пустая строка.
** 							(int) '-1'	-	Не найден ключ для парсинга
**											Получена не валидная строка.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> UNXPECTED KEY IN <.cub> FILE
**
** Особенности:				Нет.
*/

static int	ft_check_space_line(char *line)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(line);
	while (len--)
		res = (line[len] == ' ' || line[len] == '1' ? res : -1);
	return (res);
}

static int	ft_is_map(char *line)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (!(ft_isdigit(line[i])) && line[i] != '\0')
		res = -1;
	else if (line[i] == '\0')
		res = 0;
	return (res);
}

int			ft_parse_cub_elem(char *line, t_cub *cub, int fd)
{
	int	res;

	res = 0;
	if (!(ft_strncmp(line, "R ", 2)))
		res = ft_parse_cub_resolution(&line, cub);
	else if (!(ft_strncmp(line, "NO ", 3)))
		res = ft_parse_cub_sprite(&line, cub, "NO");
	else if (!(ft_strncmp(line, "SO ", 3)))
		res = ft_parse_cub_sprite(&line, cub, "SO");
	else if (!(ft_strncmp(line, "WE ", 3)))
		res = ft_parse_cub_sprite(&line, cub, "WE");
	else if (!(ft_strncmp(line, "EA ", 3)))
		res = ft_parse_cub_sprite(&line, cub, "EA");
	else if (!(ft_strncmp(line, "S ", 2)))
		res = ft_parse_cub_sprite(&line, cub, "S ");
	else if (!(ft_strncmp(line, "F ", 2)))
		res = ft_parse_cub_color(&line, cub);
	else if (!(ft_strncmp(line, "C ", 2)))
		res = ft_parse_cub_color(&line, cub);
	else if (ft_check_space_line(line) == -1)
		res = ft_putstr_fd("--> UNXPECTED KEY IN <.cub> FILE\n", 2);
	else if (ft_is_map(line))
		res = ft_parse_cub_map(&line, cub, fd);
	line = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_resolution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:53:11 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:08:06 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Парсит параметры RESOLUTION.
**
** Возвращаемое значение:	(int) '0'	-	Произошел парсинг.
** 							(int) '-1'	-	Произошла ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке:
**							--> DOUBLE DECLARATION OF [RESOLUTION]
**							--> UNXPECTED SYMBOL IN [RESOLUTION]
**							--> TOO MANY PARAM IN [RESOLUTION]
**
** Особенности:				Нет.
*/

static int	ft_get_resolution(char **line, int *tmp)
{
	int	res;

	res = 0;
	ft_move_spaces(line);
	if (ft_isdigit(**line))
		*tmp = ft_atoi(*line);
	else
		res = ft_putstr_fd("--> UNXPECTED SYMBOL IN [RESOLUTION]\n", 2);
	if ((res = ft_move_digit(line)) >= 9)
		*tmp = 100000;
	return (res);
}

int			ft_parse_cub_resolution(char **line, t_cub *cub)
{
	int	res;

	res = 0;
	(*line)++;
	if (cub->resolution.width != -1 || cub->resolution.height != -1)
		res = ft_putstr_fd("--> DOUBLE DECLARATION OF [RESOLUTION]\n", 2);
	res = (res != -1 ? ft_get_resolution(line, &cub->resolution.width) : res);
	res = (res != -1 ? ft_get_resolution(line, &cub->resolution.height) : res);
	ft_move_spaces(line);
	if (**line != '\0')
		res = ft_putstr_fd("--> TOO MANY PARAM IN [RESOLUTION]\n", 2);
	return (res);
}

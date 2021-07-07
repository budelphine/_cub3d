/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:36:54 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 22:53:04 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Парсит параметры COLOR в t_cub *cub.rgb.
**
** Возвращаемое значение:	(int) '0'	-	Произошел парсинг.
** 							(int) '-1'	-	Произошла ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке:
**							--> DOUBLE DECLARATION OF [RGB - FLOOR]
**							--> DOUBLE DECLARATION OF [RGB - SKY]
**							--> UNXPECTED SYMBOL IN [RGB]
**							--> NON COMMA SYMBOL IN [RGB]
**							--> TOO MANY PARAM IN [RGB]
**
** Особенности:				Нет.
*/

static int	ft_parse_one_rgb(char **line, int *tmp_color, char ch)
{
	int	res;

	res = 0;
	*tmp_color = 0;
	ft_move_spaces(line);
	if (ft_isdigit(**line))
		*tmp_color = ft_atoi(*line);
	else
		res = ft_putstr_fd("--> UNXPECTED SYMBOL IN [RGB]\n", 2);
	res = (res != -1 ? ft_move_digit(line) : res);
	if (res >= 4)
		res = ft_putstr_fd("--> SOME PARAM IN [RGB] IS INVALID\n", 2);
	ft_move_spaces(line);
	if (**line != ',' && ch != 'b')
		res = ft_putstr_fd("--> UNXPECTED SYMBOL IN [RGB]\n", 2);
	else if (ch != 'b')
		(*line)++;
	ft_move_spaces(line);
	return (res);
}

static int	ft_parse_color(char **line, t_rgb *rgb)
{
	int	res;

	res = 0;
	*line += 2;
	res = (res != -1 ? ft_parse_one_rgb(line, &rgb->r, 'r') : res);
	res = (res != -1 ? ft_parse_one_rgb(line, &rgb->g, 'g') : res);
	res = (res != -1 ? ft_parse_one_rgb(line, &rgb->b, 'b') : res);
	if (**line != '\0' && res != -1)
		res = ft_putstr_fd("--> TOO MANY PARAM IN [RGB]\n", 2);
	return (res);
}

static int	ft_check_double_declaration(t_rgb *rgb, char ch)
{
	int	res;

	res = 0;
	if (rgb->r != -1 || rgb->g != -1 || rgb->b != -1)
		res = -1;
	if (res == -1 && ch == 'F')
		ft_putstr_fd("--> DOUBLE DECLARATION OF [RGB - FLOOR]\n", 2);
	if (res == -1 && ch == 'C')
		ft_putstr_fd("--> DOUBLE DECLARATION OF [RGB - SKY]\n", 2);
	return (res);
}

int			ft_parse_cub_color(char **line, t_cub *cub)
{
	int	res;

	res = 0;
	if (**line == 'F')
	{
		if ((res = ft_check_double_declaration(&cub->floor, 'F')) != -1)
			res = ft_parse_color(line, &cub->floor);
	}
	else
	{
		if ((res = ft_check_double_declaration(&cub->sky, 'C')) != -1)
			res = ft_parse_color(line, &cub->sky);
	}
	return (res);
}

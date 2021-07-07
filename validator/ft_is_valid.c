/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:36:58 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/14 01:14:58 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Определяет что нужно парсить и парсит в структуру.
**
** Возвращаемое значение:	' 0'	-	Успех.
**										Аргументы карты спарсились в структуру.
** 							'-1'	-	Ошибка.
**										Ошибка файла или невалидная карта.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> [ ] IS UNSET
**							--> [ ] IS UNVALID
**
** Особенности:				Проверяет расширение файла и кол-вол аргументов,
**							переданных в программу.
*/

int	ft_is_valid(t_cub *cub)
{
	int	res;

	res = 0;
	res = ft_is_valid_resolution(cub);
	res = (res != -1 ? ft_is_valid_sprite(cub) : res);
	res = (res != -1 ? ft_is_valid_color(cub) : res);
	res = (res != -1 ? ft_is_valid_map(cub) : res);
	return ((res == -1 ? ft_free_cub(cub) : res));
}
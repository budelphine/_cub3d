/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:06:44 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:08:45 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делают функции:		Определяет какой символ подан.
**
** Возвращаемое значение:	'1'	-	Успех.
**									Тип соответствует ожидаемому.
** 							'0'	-	Ошибка.
**									Тип не соответствует ожидаемому.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> UNEXPECTD KEY IN MAP
**
** Особенности:				Нет.
*/

int	ft_is_map_key(char ch)
{
	if (ch == ' ' || ch == '0' || ch == '1' || ch == '2' \
			|| ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
		return (0);
	else
		ft_putstr_fd("--> UNEXPECTD KEY IN MAP\n", 2);
	return (-1);
}

int	ft_is_wall(char ch)
{
	if (ch == '1' || ch == ' ')
		return (1);
	return (0);
}

int	ft_is_spawn(char ch)
{
	if (ch == 'S' || ch == 'N' || ch == 'W' || ch == 'E')
		return (1);
	return (0);
}

int	ft_is_empty_line(char *line)
{
	if (*line == '\0')
		return (-1);
	return (0);
}

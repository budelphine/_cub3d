/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_resolution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:06:58 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:21:31 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Определяет корректное ли разрешение экрана.
**
** Возвращаемое значение:	' 0'	-	Успех.
** 							'-1'	-	Ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> [RESOLUTION] IS UNSET
**							--> [RESOLUTION - HEIGHT] IS UNVALID
**							--> [RESOLUTION - WIDTH] IS UNVALID
**
** Особенности:				Нет.
*/

int	ft_is_valid_resolution(t_cub *cub)
{
	int	res;

	res = 0;
	if (cub->resolution.height == -1 && cub->resolution.width == -1)
		res = ft_putstr_fd("--> [RESOLUTION] IS UNSET\n", 2);
	else if (res != -1 && cub->resolution.height < 50)
		res = ft_putstr_fd("--> [RESOLUTION - HEIGHT] IS INVALID\n", 2);
	else if (res != -1 && cub->resolution.width < 50)
		res = ft_putstr_fd("--> [RESOLUTION - WIDTH] IS INVALID\n", 2);
	if (cub->screen == 0 && cub->resolution.height > 1440)
		cub->resolution.height = 1440;
	if (cub->screen == 0 && cub->resolution.width > 2560)
		cub->resolution.width = 2560;
	return (res);
}

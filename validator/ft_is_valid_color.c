/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:08:08 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 22:53:22 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Определяет валидность FLOOR & SKY - RGB.
**
** Возвращаемое значение:	' 0'	-	Успех.
** 							'-1'	-	Ошибка.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> [ ] IS UNSET
**							--> [ ] IS INVALID
**
** Особенности:				Нет.
*/

int	ft_is_valid_color(t_cub *cub)
{
	int	res;

	res = 0;
	if (cub->floor.r == -1 && cub->floor.g == -1 && cub->floor.b == -1)
		res = ft_putstr_fd("--> [FLOOR - RGB] IS UNSET\n", 2);
	if (res != -1 && cub->sky.r == -1 && cub->sky.g == -1 && cub->sky.b == -1)
		res = ft_putstr_fd("--> [SKY - RGB] IS UNSET\n", 2);
	if (res != -1 && (cub->floor.r < 0 || cub->floor.g < 0 || cub->floor.b < 0))
		res = ft_putstr_fd("--> [FLOOR - RGB] IS INVALID\n", 2);
	if (res != -1 && (cub->floor.r > 255 || cub->floor.g > 255 \
														|| cub->floor.b > 255))
		res = ft_putstr_fd("--> [FLOOR - RGB] IS INVALID\n", 2);
	if (res != -1 && (cub->sky.r < 0 || cub->sky.g < 0 || cub->sky.b < 0))
		res = ft_putstr_fd("--> [SKY - RGB] IS INVALID\n", 2);
	if (res != -1 && (cub->sky.r > 255 || cub->sky.g > 255 || cub->sky.b > 255))
		res = ft_putstr_fd("--> [SKY - RGB] IS INVALID\n", 2);
	return (res);
}

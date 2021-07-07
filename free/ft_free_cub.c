/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:23:02 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 20:11:12 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Чистит структуру t_cub.
**
** Возвращаемое значение:	'-1'	-	Успех.
**										Структура очищена.
**
** Дополнительно:			Выводит сообщение.
**							--> CUB_STRUCT IS FREE
**
** Особенности:				Нет.
*/

int		ft_free_cub(t_cub *cub)
{
	cub->resolution.height = -1;
	cub->resolution.width = -1;
	ft_strdel(&(cub->path.no));
	ft_strdel(&(cub->path.so));
	ft_strdel(&(cub->path.we));
	ft_strdel(&(cub->path.ea));
	ft_strdel(&(cub->path.spr));
	cub->sky = ft_make_rgb_struct(-1, -1, -1);
	cub->floor = ft_make_rgb_struct(-1, -1, -1);
	if (cub->map != NULL)
		ft_remove_arr(cub->map, ft_strlen_y(cub->map));
	ft_putstr_fd("--> CUB_STRUCT IS FREE\n", 2);
	ft_putstr_fd("\n--> 42. PROGRAM FAILURE\n", 2);
	ft_putstr_fd("\n--> PROGRAM END!\n", 2);
	return (-1);
}

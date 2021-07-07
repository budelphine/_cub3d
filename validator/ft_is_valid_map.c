/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:44:25 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:09:18 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делают функции:		Определяет валидность карты
**
** Возвращаемое значение:	' 0'	-	Успех.
**										Карта валидна.
** 							'-1'	-	Ошибка.
**										Карта не валидна.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							--> MALLOC ERROR IN [NEW MAP]
**							--> THE [MAP] IS UNVALID
**
** Особенности:				Создает новый массив i * j_max
**							и дополняет пустоты пробелами.
*/

static int	ft_check_place_around_spaces(char **map, int y, int x)
{
	int	len_x;
	int	len_y;
	int	flag;
	int	max_flag;

	flag = 0;
	max_flag = 4;
	len_x = ft_strlen(map[0]) - 1;
	len_y = ft_strlen_y(map) - 1;
	if (!ft_is_wall(map[y][x]) \
		&& (x == 0 || y == 0 || x == len_x || y == len_y))
		return (-1);
	if (map[y][x] != ' ')
		return (0);
	x < len_x ? flag += ft_is_wall(map[y][x + 1]) : max_flag--;
	y < len_y ? flag += ft_is_wall(map[y + 1][x]) : max_flag--;
	x > 0 ? flag += ft_is_wall(map[y][x - 1]) : max_flag--;
	y > 0 ? flag += ft_is_wall(map[y - 1][x]) : max_flag--;
	return (flag == max_flag ? 1 : -1);
}

static int	ft_check_valid_map(char **map)
{
	int		res;
	int		y;
	int		x;
	int		spawn;

	y = 0;
	x = 0;
	res = 0;
	spawn = 0;
	while (map[y] != '\0' && res != -1)
	{
		x = 0;
		res = (ft_is_empty_line(map[y]) == -1 ? -1 : res);
		while (map[y][x] != '\0' && res != -1)
		{
			res = (ft_is_map_key(map[y][x]) == -1 ? -1 : res);
			spawn += ft_is_spawn(map[y][x]);
			res = (spawn > 1 ? -1 : res);
			res = (ft_check_place_around_spaces(map, y, x) == -1 ? -1 : res);
			x++;
		}
		y++;
	}
	return (spawn != 1 ? -1 : res);
}

int			ft_is_valid_map(t_cub *cub)
{
	int	res;

	res = 0;
	if (!(cub->map = ft_create_new_array(cub->map)))
		return (ft_putstr_fd("--> MALLOC ERROR IN [NEW MAP]\n", 2));
	res = ft_check_valid_map(cub->map);
	if (res == -1)
		ft_putstr_fd("--> THE [MAP] IS UNVALID\n", 2);
	return (res);
}

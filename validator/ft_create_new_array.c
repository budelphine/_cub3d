/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:18:21 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:09:25 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делают функции:		Создает новую карту i * j_max
**							и дополняет пустоты пробелами.
**
** Возвращаемое значение:	'char **'	-	Успех. Возвращает
**											указатель на новую карту.
** 							'  NULL'	-	Ошибка.
**											Карта не создана.
**
** Дополнительно:			Нет.
**
** Особенности:				Нет.
*/

static void	ft_get_line_with_spaces(char *src, char *dest, int j_max)
{
	int i;

	i = 0;
	while (src[i] != '\0' && src[0] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < j_max && src[0] != '\0')
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
}

static char	**ft_new_arr_jmax(char **map, int i_max, int j_max)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_map = (char **)malloc(sizeof(char *) * (i_max + 1));
	if (!new_map)
		return (NULL);
	while (i < i_max)
	{
		if (!(new_map[i] = (char *)malloc(sizeof(char) * (j_max + 1))))
			return (ft_remove_arr(new_map, i));
		new_map[i][j_max + 1] = '\0';
		ft_get_line_with_spaces(map[i], new_map[i], j_max);
		i++;
	}
	ft_remove_arr(map, i_max);
	new_map[i_max] = NULL;
	return (new_map);
}

char		**ft_create_new_array(char **map)
{
	int		i;
	int		j;
	int		j_max;

	i = 0;
	j = 0;
	j_max = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j > j_max)
			j_max = j;
		i++;
	}
	return (ft_new_arr_jmax(map, i, j_max));
}

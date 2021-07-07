/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:15:15 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:13:53 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Что делает функция:		Парсит параметры из файла <.cub>
**							в структуру t_cub.
**
** Возвращаемое значение:	' 0'	-	Успех.
**										Аргументы карты спарсились в структуру.
** 							'-1'	-	Ошибка.
**										Ошибка GNL или невалидная карта.
**
** Дополнительно:			Выводит сообщение об ошибке.
**							-->  MALLOC ERROR IN [GNL]
**
** Особенности:				Обрабатывает ошибки gnl.	--> Чистит t_cub.
**							Обрабатывает ошибки parser.	--> Чистит t_cub.
*/

int		ft_parse_cub(int fd, t_cub *cub)
{
	char	*line;
	int		gnl;
	int		res;

	res = 0;
	ft_init_cub_struct(cub);
	while (((gnl = get_next_line(fd, &line)) > 0) && res != -1)
	{
		res = ft_parse_cub_elem(line, cub, fd);
		free(line);
	}
	free(line);
	line = NULL;
	res = (gnl == -1 ? ft_putstr_fd("-->  MALLOC ERROR IN [GNL]\n", 2) : res);
	res = (res == -1 ? ft_free_cub(cub) : res);
	return (res);
}

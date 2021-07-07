/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:43:14 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:21:43 by budelphi         ###   ########.fr       */
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
**							--> MAP FILE_NAME <.cub> IS TOO SHORT
**							--> INVALID MAP FILE EXTENTION <.>
**							--> TOO FEW ARGUMENT
**							--> TOO MANY ARGUMENT
**							--> CANNOT OPEN MAP FILE
**
** Особенности:				Проверяет расширение файла и кол-вол аргументов,
**							переданных в программу.
*/

static int	ft_check_ac(int ac, char **av, t_cub *cub)
{
	int	res;

	res = 0;
	if (ac < 2)
		res = ft_putstr_fd("--> TOO FEW ARGUMENT\n", 2);
	if (ac == 3 && !(ft_strncmp(av[2], "--save", 7)))
		cub->screen = 1;
	else
		cub->screen = 0;
	if (ac > 2 & cub->screen == 0)
		res = ft_putstr_fd("--> TOO MANY ARGUMENT\n", 2);
	return (res);
}

int			ft_parser(int ac, char **av, t_cub *cub)
{
	int	res;
	int	fd;

	res = 0;
	res = ft_check_ac(ac, av, cub);
	if (res != -1)
		res = ft_check_file_ext(av[1], ".cub");
	if (!(fd = open(av[1], O_RDWR)) && res != -1)
		res = ft_putstr_fd("--> CANNOT OPEN MAP FILE\n", 2);
	if (res != -1)
		res = ft_parse_cub(fd, cub);
	if (fd > 0)
		close(fd);
	return (res);
}

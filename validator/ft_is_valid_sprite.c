/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:05:40 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:09:11 by budelphi         ###   ########.fr       */
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
**							--> [PATH - ] IS UNSET
**							--> CANNOT OPEN [PATH - ] SPRITE
**							--> INVALID FILE EXTENTION IN []
**
** Особенности:				Проверяет расширение файла.
**							Нормально ли он открывается.
**							Задан ли путь ко всем спрайтам.
*/

static int	ft_is_correct_path(t_cub *cub)
{
	int	res;
	int	fd;

	res = 0;
	if ((fd = open(cub->path.no, O_RDWR)) < 0)
		res = ft_putstr_fd("--> CANNOT OPEN [PATH - NO] SPRITE\n", 2);
	else
		close(fd);
	if ((fd = open(cub->path.so, O_RDWR)) < 0)
		res = ft_putstr_fd("--> CANNOT OPEN [PATH - SO] SPRITE\n", 2);
	else
		close(fd);
	if ((fd = open(cub->path.we, O_RDWR)) < 0)
		res = ft_putstr_fd("--> CANNOT OPEN [PATH - WE] SPRITE\n", 2);
	else
		close(fd);
	if ((fd = open(cub->path.ea, O_RDWR)) < 0)
		res = ft_putstr_fd("--> CANNOT OPEN [PATH - EA] SPRITE\n", 2);
	else
		close(fd);
	if ((fd = open(cub->path.spr, O_RDWR)) < 0)
		res = ft_putstr_fd("--> CANNOT OPEN [PATH - SPRITE] SPRITE\n", 2);
	else
		close(fd);
	return (res);
}

static int	ft_is_correct_ext(t_cub *cub)
{
	if (ft_check_file_ext(cub->path.no, ".xpm") == -1)
		return (-1);
	else if (ft_check_file_ext(cub->path.so, ".xpm") == -1)
		return (-1);
	else if (ft_check_file_ext(cub->path.we, ".xpm") == -1)
		return (-1);
	else if (ft_check_file_ext(cub->path.ea, ".xpm") == -1)
		return (-1);
	else if (ft_check_file_ext(cub->path.spr, ".xpm") == -1)
		return (-1);
	return (0);
}

static int	ft_is_unset_path(t_cub *cub)
{
	int	res;

	res = 0;
	if (cub->path.no == NULL)
		res = ft_putstr_fd("--> [PATH - NO] IS UNSET\n", 2);
	if (cub->path.so == NULL)
		res = ft_putstr_fd("--> [PATH - SO] IS UNSET\n", 2);
	if (cub->path.we == NULL)
		res = ft_putstr_fd("--> [PATH - WE] IS UNSET\n", 2);
	if (cub->path.ea == NULL)
		res = ft_putstr_fd("--> [PATH - EA] IS UNSET\n", 2);
	if (cub->path.spr == NULL)
		res = ft_putstr_fd("--> [PATH - SPRITE] IS UNSET\n", 2);
	return (res);
}

int			ft_is_valid_sprite(t_cub *cub)
{
	int	res;

	res = 0;
	res = ft_is_unset_path(cub);
	if (res != -1)
		res = ft_is_correct_ext(cub);
	if (res != -1)
		res = ft_is_correct_path(cub);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:17:03 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:08:51 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_file_ext(char *file_name, char *ext)
{
	int	len;

	len = 0;
	len = ft_strlen(file_name);
	if (len < 5)
	{
		ft_putstr_fd("--> FILE_NAME OF ' ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" ' IS TOO SHORT\n", 2);
		return (-1);
	}
	if (ft_strncmp(&file_name[len - 4], ext, 5))
	{
		ft_putstr_fd("--> INVALID FILE EXTENTION IN ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" \n", 2);
		return (-1);
	}
	return (0);
}

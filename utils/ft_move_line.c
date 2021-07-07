/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:39:24 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 22:43:19 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_move_digit(char **line)
{
	int	res;

	res = 0;
	while (**line != '\0' && **line == '0')
		(*line)++;
	while (**line != '\0' && ft_isdigit(**line))
	{
		res++;
		(*line)++;
	}
	return (res);
}

void	ft_move_non_spaces(char **line)
{
	while (**line != '\0' && **line != ' ')
		(*line)++;
}

void	ft_move_spaces(char **line)
{
	while (**line != '\0' && **line == ' ')
		(*line)++;
}

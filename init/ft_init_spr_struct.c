/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_spr_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:04:32 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 20:08:45 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_spr_struct(t_all *all, t_spr *spr)
{
	int	y;
	int	x;

	y = -1;
	spr->cur = 0;
	spr->max = 0;
	spr->arr = NULL;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
			spr->max += (all->map[y][x] == '2' ? 1 : 0);
	}
}

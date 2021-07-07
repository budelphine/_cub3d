/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:48:47 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 20:00:06 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_spr_arr_of_xy(t_all *all, t_spr_arr arr[])
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '2')
			{
				arr[i].x = x + 0.5;
				arr[i].y = y + 0.5;
				i++;
			}
		}
	}
}

static void	ft_sort_sprite(t_all *all, t_spr_arr arr[])
{
	t_spr_arr		tmp;
	int				i;
	int				j;

	i = -1;
	while (++i < all->spr->max)
	{
		j = all->spr->max;
		while (--j > i)
		{
			if (arr[j].dist > arr[j - 1].dist)
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void		ft_init_sprite_arr(t_all *all, t_spr_arr arr[], int i)
{
	t_spr	*spr;
	t_plr	*plr;

	spr = all->spr;
	plr = all->plr;
	ft_init_spr_arr_of_xy(all, arr);
	while (++i < spr->max)
	{
		arr[i].dist = ((plr->pos_x - arr[i].x) * (plr->pos_x - arr[i].x) \
						+ (plr->pos_y - arr[i].y) * (plr->pos_y - arr[i].y));
	}
	ft_sort_sprite(all, arr);
}

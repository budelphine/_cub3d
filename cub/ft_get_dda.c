/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:42:30 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 19:36:07 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_dda(t_all *all, t_plr *plr)
{
	plr->hit = 0;
	while (plr->hit == 0)
	{
		if (plr->side_dist_x < plr->side_dist_y)
		{
			plr->side_dist_x += plr->delta_dist_x;
			plr->map_x += plr->step_x;
			plr->side = 0;
		}
		else
		{
			plr->side_dist_y += plr->delta_dist_y;
			plr->map_y += plr->step_y;
			plr->side = 1;
		}
		if (!ft_strchr("02NEWS", all->map[plr->map_y][plr->map_x]) \
			|| all->map[plr->map_y][plr->map_x] == '\0')
			plr->hit = 1;
	}
	if (plr->side == 0)
		plr->perp_wall_dist = (plr->map_x - plr->pos_x + (1 - plr->step_x) / 2)
								/ plr->ray_dir_x;
	else
		plr->perp_wall_dist = (plr->map_y - plr->pos_y + (1 - plr->step_y) / 2)
								/ plr->ray_dir_y;
}

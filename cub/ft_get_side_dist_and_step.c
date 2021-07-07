/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_side_dist_and_step.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:46:21 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 19:19:07 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_side_dist_and_step(t_plr *plr)
{
	if (plr->ray_dir_x < 0)
	{
		plr->step_x = -1;
		plr->side_dist_x = (plr->pos_x - plr->map_x) * plr->delta_dist_x;
	}
	else
	{
		plr->step_x = 1;
		plr->side_dist_x = (plr->map_x + 1.0 - plr->pos_x) * plr->delta_dist_x;
	}
	if (plr->ray_dir_y < 0)
	{
		plr->step_y = -1;
		plr->side_dist_y = (plr->pos_y - plr->map_y) * plr->delta_dist_y;
	}
	else
	{
		plr->step_y = 1;
		plr->side_dist_y = (plr->map_y + 1.0 - plr->pos_y) * plr->delta_dist_y;
	}
}

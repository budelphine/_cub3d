/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_delta_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:49:42 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 19:34:53 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_delta_dist(t_plr *plr)
{
	if (plr->ray_dir_y == 0)
		plr->delta_dist_x = 0;
	else
		plr->delta_dist_x = ((plr->ray_dir_x == 0) ? 1 \
						: fabs(1 / plr->ray_dir_x));
	if (plr->ray_dir_x == 0)
		plr->delta_dist_y = 0;
	else
		plr->delta_dist_y = ((plr->ray_dir_y == 0) ? 1 \
						: fabs(1 / plr->ray_dir_y));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:53:13 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 14:44:34 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_start_value(int x, double s_width, t_plr *plr)
{
	plr->cam_x = 2 * x / s_width - 1;
	plr->ray_dir_x = plr->dir_x + plr->plane_x * plr->cam_x;
	plr->ray_dir_y = plr->dir_y + plr->plane_y * plr->cam_x;
	plr->map_x = (int)plr->pos_x;
	plr->map_y = (int)plr->pos_y;
}

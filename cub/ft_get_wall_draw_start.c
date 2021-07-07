/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wall_draw_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:58:07 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 19:18:46 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_wall_draw_start(t_plr *plr, int s_height)
{
	plr->line_h = (int)(s_height / plr->perp_wall_dist);
	plr->draw_s = -plr->line_h / 2 + s_height / 2;
	plr->draw_e = plr->line_h / 2 + s_height / 2;
	plr->draw_s = (plr->draw_s < 0 ? 0 : plr->draw_s);
	plr->draw_e = (plr->draw_e >= s_height ? s_height - 1 : plr->draw_e);
}

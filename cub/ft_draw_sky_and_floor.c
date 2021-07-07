/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sky_and_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:12:20 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 20:34:29 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static unsigned long	ft_to_rgb(t_rgb *rgb)
{
	return (((rgb->r & 0xff) << 16)	\
			+ ((rgb->g & 0xff) << 8) + (rgb->b & 0xff));
}

void					ft_draw_sky_and_floor(t_all *all, t_plr *plr)
{
	int	y;
	int	s_height;

	y = 0;
	s_height = all->cub->resolution.height;
	while (y < plr->draw_s)
	{
		plr->color = ft_to_rgb(&all->cub->sky);
		my_mlx_pixel_put(all->mlx, all->x, y, plr->color);
		y++;
	}
	y = plr->draw_e;
	while (y < s_height)
	{
		plr->color = ft_to_rgb(&all->cub->floor);
		my_mlx_pixel_put(all->mlx, all->x, y, plr->color);
		y++;
	}
	plr->color = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:56:54 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 19:18:36 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_render_cub(t_plr *plr, t_all *all)
{
	int		h;
	double	w;
	double	z_buf[all->cub->resolution.width + 1];

	w = (double)all->cub->resolution.width;
	h = all->cub->resolution.height;
	all->x = 0;
	while (all->x < w)
	{
		ft_get_start_value(all->x, w, plr);
		ft_get_delta_dist(plr);
		ft_get_side_dist_and_step(plr);
		ft_get_dda(all, plr);
		ft_get_wall_draw_start(plr, h);
		ft_draw_sky_and_floor(all, plr);
		ft_get_textured_wall(all, plr);
		z_buf[all->x] = plr->perp_wall_dist;
		all->x++;
	}
	ft_draw_sprites(all, plr, all->spr, z_buf);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, 0, 0);
	return (0);
}

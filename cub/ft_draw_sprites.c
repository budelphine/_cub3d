/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:34:05 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 19:16:29 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_draw_stripe(t_all *all, t_spr *spr, t_plr *plr, double z_buf[])
{
	spr->stripe = spr->draw_sx;
	while (spr->stripe <= spr->draw_ex)
	{
		spr->tex_x = (int)((256 * (spr->stripe - (-spr->width / 2 \
				+ spr->screen_x)) * all->tex->spr.width / spr->width) / 256);
		if (spr->ts_y > 0 && spr->stripe >= 0 \
			&& spr->stripe < all->cub->resolution.width \
			&& spr->ts_y < z_buf[spr->stripe])
		{
			spr->y = spr->draw_sy;
			while (spr->y <= spr->draw_ey)
			{
				spr->d = ((spr->y - spr->vmove_screen) * 256 \
				- all->cub->resolution.height * 128 + spr->height * 128);
				spr->tex_y = ((spr->d * all->tex->spr.height) \
							/ spr->height) / 256;
				plr->color = ft_get_color(&all->tex->spr, \
							plr, spr->tex_x, spr->tex_y);
				if ((plr->color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all->mlx, spr->stripe, spr->y, plr->color);
				spr->y++;
			}
		}
		spr->stripe++;
	}
}

static void	ft_sprite_height_and_width(t_all *all)
{
	t_spr	*spr;
	int		h;
	int		w;

	h = all->cub->resolution.height;
	w = all->cub->resolution.width;
	spr = all->spr;
	spr->height = abs((int)(all->cub->resolution.height / (spr->ts_y))) / VDIV;
	spr->draw_sy = -spr->height / 2 + h / 2 + spr->vmove_screen;
	spr->draw_ey = spr->height / 2 + h / 2 + spr->vmove_screen;
	spr->draw_sy = (spr->draw_sy < 0 ? 0 : spr->draw_sy);
	spr->draw_ey = (spr->draw_ey >= h ? h - 1 : spr->draw_ey);
	spr->width = abs((int)(w / spr->ts_y));
	spr->draw_sx = -(spr->width) / 2 + spr->screen_x;
	spr->draw_ex = spr->width / 2 + spr->screen_x;
	spr->draw_sx = (spr->draw_sx < 0 ? 0 : spr->draw_sx);
	spr->draw_ex = (spr->draw_ex >= w ? w - 1 : spr->draw_ex);
}

static void	ft_sprite_of_cam(t_all *all, t_spr_arr arr[], int i)
{
	t_spr	*spr;
	t_plr	*plr;
	int		w;

	w = all->cub->resolution.width;
	spr = all->spr;
	plr = all->plr;
	spr->spr_x = arr[i].x - plr->pos_x;
	spr->spr_y = arr[i].y - plr->pos_y;
	spr->inv_det = 1.0 / (plr->plane_x * plr->dir_y \
						- plr->dir_x * plr->plane_y);
	spr->ts_x = spr->inv_det * (plr->dir_y * spr->spr_x \
						- plr->dir_x * spr->spr_y);
	spr->ts_y = spr->inv_det * (-(plr->plane_y) * spr->spr_x \
						+ plr->plane_x * spr->spr_y);
	spr->screen_x = (int)((w / 2) * (1 + spr->ts_x / spr->ts_y));
	spr->vmove_screen = (int)(VMOVE / spr->ts_y);
}

void		ft_draw_sprites(t_all *all, t_plr *plr, t_spr *spr, double z_buf[])
{
	t_spr_arr	arr[spr->max + 1];
	int			i;

	i = -1;
	ft_init_sprite_arr(all, arr, i);
	while (++i < spr->max)
	{
		ft_sprite_of_cam(all, arr, i);
		ft_sprite_height_and_width(all);
		ft_draw_stripe(all, spr, plr, z_buf);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textured_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:13:03 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 16:22:29 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_textured_wall(t_all *all, t_plr *plr, t_xpm *tmp)
{
	int	h;

	h = all->cub->resolution.height;
	if (plr->side == 0)
		plr->wall_x = plr->pos_y + plr->perp_wall_dist * plr->ray_dir_y;
	else
		plr->wall_x = plr->pos_x + plr->perp_wall_dist * plr->ray_dir_x;
	plr->wall_x -= floor((plr->wall_x));
	plr->tex_x = (int)(plr->wall_x * (double)(tmp->width));
	if (plr->side == 0 && plr->ray_dir_x > 0)
		plr->tex_x = tmp->width - plr->tex_x - 1;
	if (plr->side == 1 && plr->ray_dir_y < 0)
		plr->tex_x = tmp->width - plr->tex_x - 1;
	plr->step = 1.0 * tmp->height / plr->line_h;
	plr->tex_pos = (plr->draw_s - h / 2 + plr->line_h / 2) * plr->step;
	while (plr->draw_s <= plr->draw_e)
	{
		plr->tex_y = (int)plr->tex_pos;
		plr->tex_pos += plr->step;
		plr->color = ft_get_color(tmp, plr, plr->tex_x, plr->tex_y);
		my_mlx_pixel_put(all->mlx, all->x, plr->draw_s++, plr->color);
	}
}

void	ft_get_textured_wall(t_all *all, t_plr *plr)
{
	t_xpm	*tmp;

	if (plr->side == 0 && plr->map_x < plr->pos_x)
		tmp = &all->tex->we;
	else if (plr->side == 0 && plr->map_x > plr->pos_x)
		tmp = &all->tex->ea;
	else if (plr->side == 1 && plr->map_y < plr->pos_y)
		tmp = &all->tex->no;
	else if (plr->side == 1 && plr->map_y > plr->pos_y)
		tmp = &all->tex->so;
	else
		tmp = &all->tex->we;
	ft_draw_textured_wall(all, plr, tmp);
}

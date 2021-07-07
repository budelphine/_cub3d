/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plr_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:59:36 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 19:14:44 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_set_plr_pos(t_all *all, t_plr *plr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' \
			|| all->map[y][x] == 'W' || all->map[y][x] == 'E')
			{
				plr->pos_x = (double)x + 0.5;
				plr->pos_y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
}

static void	ft_rot_spawn(t_plr *plr, char spawn)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = plr->dir_x;
	old_plane_x = plr->plane_x;
	rot = 3.14159265359;
	if (spawn == 'N')
		rot = 0.5 * rot;
	if (spawn == 'W')
		rot = 1 * rot;
	if (spawn == 'S')
		rot = 1.5 * rot;
	if (spawn == 'E')
		rot = 2 * rot;
	plr->dir_x = plr->dir_x * cos(-rot) - plr->dir_y * sin(-rot);
	plr->dir_y = old_dir_x * sin(-rot) + plr->dir_y * cos(-rot);
	plr->plane_x = plr->plane_x * cos(-rot) - plr->plane_y * sin(-rot);
	plr->plane_y = old_plane_x * sin(-rot) + plr->plane_y * cos(-rot);
}

static void	ft_set_dir_xy(t_all *all)
{
	int		y;
	int		x;
	char	spawn;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' \
			|| all->map[y][x] == 'W' || all->map[y][x] == 'E')
				spawn = all->map[y][x];
		}
	}
	ft_rot_spawn(all->plr, spawn);
}

static void	ft_set_dir_and_plane(t_plr *plr)
{
	plr->dir_x = 1;
	plr->dir_y = 0;
	plr->plane_x = 0;
	plr->plane_y = 0.66;
}

void		ft_init_plr_struct(t_all *all, t_plr *plr)
{
	ft_set_dir_and_plane(plr);
	ft_set_plr_pos(all, plr);
	ft_set_dir_xy(all);
}

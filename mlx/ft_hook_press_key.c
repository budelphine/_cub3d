/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_press_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:54:49 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 20:05:56 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_esc_window(int key)
{
	if (key == 53)
	{
		ft_putstr("--> PROGRAM END!\n");
		exit(0);
	}
}

static void	ft_move_up_and_down(int key, char **m, t_plr *plr)
{
	if (key == 13 || key == 126)
	{
		if (m[(int)(plr->pos_y)][(int)(plr->pos_x + plr->dir_x * DS)] != '1'
			&& m[(int)(plr->pos_y)][(int)(plr->pos_x + plr->dir_x * DS)] != 0)
			plr->pos_x += plr->dir_x * MS;
		if (m[(int)(plr->pos_y + plr->dir_y * DS)][(int)(plr->pos_x)] != '1'
			&& m[(int)(plr->pos_y + plr->dir_y * DS)][(int)(plr->pos_x)] != 0)
			plr->pos_y += plr->dir_y * MS;
	}
	else if (key == 1 || key == 125)
	{
		if (m[(int)(plr->pos_y)][(int)(plr->pos_x - plr->dir_x * DS)] != '1'
			&& m[(int)(plr->pos_y)][(int)(plr->pos_x - plr->dir_x * DS)] != 0)
			plr->pos_x -= plr->dir_x * MS;
		if (m[(int)(plr->pos_y - plr->dir_y * DS)][(int)(plr->pos_x)] != '1'
			&& m[(int)(plr->pos_y - plr->dir_y * DS)][(int)(plr->pos_x)] != 0)
			plr->pos_y -= plr->dir_y * MS;
	}
}

static void	ft_move_left_and_right(int key, char **m, t_plr *plr)
{
	if (key == 123)
	{
		if (m[(int)(plr->pos_y)][(int)(plr->pos_x - plr->plane_x * DS)] != '1'
			&& m[(int)(plr->pos_y)][(int)(plr->pos_x - plr->plane_x * DS)] != 0)
			plr->pos_x -= plr->plane_x * MS;
		if (m[(int)(plr->pos_y - plr->plane_y * DS)][(int)(plr->pos_x)] != '1'
			&& m[(int)(plr->pos_y - plr->plane_y * DS)][(int)(plr->pos_x)] != 0)
			plr->pos_y -= plr->plane_y * MS;
	}
	else if (key == 124)
	{
		if (m[(int)(plr->pos_y)][(int)(plr->pos_x + plr->plane_x * DS)] != '1'
			&& m[(int)(plr->pos_y)][(int)(plr->pos_x + plr->plane_x * DS)] != 0)
			plr->pos_x += plr->plane_x * MS;
		if (m[(int)(plr->pos_y + plr->plane_y * DS)][(int)(plr->pos_x)] != '1'
			&& m[(int)(plr->pos_y + plr->plane_y * DS)][(int)(plr->pos_x)] != 0)
			plr->pos_y += plr->plane_y * MS;
	}
}

static void	ft_rot_left_and_right(int key, t_plr *plr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = plr->dir_x;
	old_plane_x = plr->plane_x;
	if (key == 0)
	{
		plr->dir_x = plr->dir_x * cos(-RS) - plr->dir_y * sin(-RS);
		plr->dir_y = old_dir_x * sin(-RS) + plr->dir_y * cos(-RS);
		plr->plane_x = plr->plane_x * cos(-RS) - plr->plane_y * sin(-RS);
		plr->plane_y = old_plane_x * sin(-RS) + plr->plane_y * cos(-RS);
	}
	else if (key == 2)
	{
		plr->dir_x = plr->dir_x * cos(RS) - plr->dir_y * sin(RS);
		plr->dir_y = old_dir_x * sin(RS) + plr->dir_y * cos(RS);
		plr->plane_x = plr->plane_x * cos(RS) - plr->plane_y * sin(RS);
		plr->plane_y = old_plane_x * sin(RS) + plr->plane_y * cos(RS);
	}
}

int			ft_hook_press_key(int key, t_all *all)
{
	t_plr	*plr;

	plr = all->plr;
	if (key == 13 || key == 0 || key == 1 || key == 2
		|| key == 126 || key == 125 || key == 123 || key == 124)
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
	ft_move_up_and_down(key, all->map, plr);
	ft_move_left_and_right(key, all->map, plr);
	ft_rot_left_and_right(key, plr);
	ft_esc_window(key);
	if (key == 13 || key == 0 || key == 1 || key == 2
		|| key == 126 || key == 125 || key == 123 || key == 124)
		ft_render_cub(plr, all);
	return (0);
}

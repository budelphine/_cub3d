/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:12:26 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:10:32 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_exit(int key, t_all *all)
{
	ft_putstr("--> PROGRAM END!\n");
	if (all)
		exit(0);
	return (key);
}

int			ft_cub_2d(t_all *all)
{
	ft_init_all(all);
	mlx_hook(all->mlx->win, 2, (1L << 0), &ft_hook_press_key, all);
	mlx_hook(all->mlx->win, 17, 0, &ft_exit, all);
	ft_render_cub(all->plr, all);
	all->cub->screen = (all->cub->screen == 1 ? ft_get_screenshot(all) : 0);
	mlx_loop(all->mlx);
	return (0);
}

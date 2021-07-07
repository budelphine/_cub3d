/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:58:44 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:07:23 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_all(t_all *all)
{
	int	res;

	res = 0;
	all->map = all->cub->map;
	ft_init_plr_struct(all, all->plr);
	ft_init_spr_struct(all, all->spr);
	res = ft_init_tex_struct(all, all->mlx->mlx, all->tex);
}

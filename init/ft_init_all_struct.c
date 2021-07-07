/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:49:48 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:03:40 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_init_all_struct(t_all *all)
{
	int	res;

	res = 0;
	if (!(all->cub = (t_cub *)malloc(sizeof(t_cub))))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [INIT T_ALL->CUB]\n", 2));
	if (!(all->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [INIT T_ALL->MLX]\n", 2));
	if (!(all->plr = (t_plr *)malloc(sizeof(t_plr))))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [INIT T_ALL->PLR]\n", 2));
	if (!(all->tex = (t_tex *)malloc(sizeof(t_tex))))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [INIT T_ALL->TEX]\n", 2));
	if (!(all->spr = (t_spr *)malloc(sizeof(t_spr))))
		return (ft_putstr_fd("-->  MALLOC ERROR IN [INIT T_ALL->_INFO\n", 2));
	all->map = NULL;
	return (res);
}

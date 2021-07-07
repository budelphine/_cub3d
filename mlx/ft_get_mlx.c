/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:15:25 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 21:07:21 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_mlx(t_mlx *mlx, t_cub *cub)
{
	int	w;
	int	h;

	h = cub->resolution.height;
	w = cub->resolution.width;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, w, h, "CUB3D");
	mlx->img = mlx_new_image(mlx, w, h);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_l, &mlx->enn);
	return (0);
}

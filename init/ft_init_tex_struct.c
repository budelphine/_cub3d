/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:03:24 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 16:23:07 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_get_tex_img_and_addr(void *mlx, t_xpm *tmp)
{
	int	res;

	res = 0;
	tmp->img = mlx_xpm_file_to_image(mlx, tmp->path, &tmp->width, &tmp->height);
	res = (!tmp->img ? ft_putstr_fd("ERROR IN mlx_xpm_file_to_img", 2) : res);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp, &tmp->line_l, &tmp->enn);
	return (res);
}

int			ft_init_tex_struct(t_all *all, void *mlx, t_tex *tex)
{
	int	res;

	res = 0;
	tex->no.path = all->cub->path.no;
	tex->so.path = all->cub->path.so;
	tex->we.path = all->cub->path.we;
	tex->ea.path = all->cub->path.ea;
	tex->spr.path = all->cub->path.spr;
	res = (res != -1 ? ft_get_tex_img_and_addr(mlx, &(tex->no)) : res);
	res = (res != -1 ? ft_get_tex_img_and_addr(mlx, &(tex->so)) : res);
	res = (res != -1 ? ft_get_tex_img_and_addr(mlx, &(tex->we)) : res);
	res = (res != -1 ? ft_get_tex_img_and_addr(mlx, &(tex->ea)) : res);
	res = (res != -1 ? ft_get_tex_img_and_addr(mlx, &(tex->spr)) : res);
	res = (res == -1 ? ft_putstr_fd("ERROR IN mlx_xpm_to_file", 2) : res);
	return (res);
}

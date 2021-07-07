/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:27:48 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:14:02 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rgb	ft_make_rgb_struct(int r, int g, int b)
{
	t_rgb	tmp_rgb;

	tmp_rgb.r = r;
	tmp_rgb.g = g;
	tmp_rgb.b = b;
	return (tmp_rgb);
}

int		ft_init_cub_struct(t_cub *cub)
{
	cub->resolution.height = -1;
	cub->resolution.width = -1;
	cub->path.no = NULL;
	cub->path.so = NULL;
	cub->path.we = NULL;
	cub->path.ea = NULL;
	cub->path.spr = NULL;
	cub->floor = ft_make_rgb_struct(-1, -1, -1);
	cub->sky = ft_make_rgb_struct(-1, -1, -1);
	cub->map = NULL;
	return (0);
}

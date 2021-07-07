/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_screenshot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:33:15 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:24:08 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_make_head(unsigned char *bmp_head, \
			unsigned char *bmp_fhead, t_all *all)
{
	int		size;

	size = 14 + 40 + all->cub->resolution.width * all->cub->resolution.height
			* all->mlx->bpp / 8;
	bmp_head[0] = 'B';
	bmp_head[1] = 'M';
	bmp_head[2] = (unsigned char)(size);
	bmp_head[3] = (unsigned char)(size >> 8);
	bmp_head[4] = (unsigned char)(size >> 16);
	bmp_head[5] = (unsigned char)(size >> 24);
	bmp_head[10] = (unsigned char)(54);
	bmp_fhead[0] = (unsigned char)(40);
	bmp_fhead[4] = (unsigned char)(all->cub->resolution.width);
	bmp_fhead[5] = (unsigned char)(all->cub->resolution.width >> 8);
	bmp_fhead[6] = (unsigned char)(all->cub->resolution.width >> 16);
	bmp_fhead[7] = (unsigned char)(all->cub->resolution.width >> 24);
	bmp_fhead[8] = (unsigned char)(-all->cub->resolution.height);
	bmp_fhead[9] = (unsigned char)(-all->cub->resolution.height >> 8);
	bmp_fhead[10] = (unsigned char)(-all->cub->resolution.height >> 16);
	bmp_fhead[11] = (unsigned char)(-all->cub->resolution.height >> 24);
	bmp_fhead[12] = (unsigned char)(1);
	bmp_fhead[14] = (unsigned char)(all->mlx->bpp);
	return (0);
}

static int	ft_make_file_scr(unsigned char *bmp_head, \
			unsigned char *bmp_fhead, t_all *all)
{
	int		fd;
	char	*filename;
	int		i;
	int		size;

	filename = "screen.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		return (-1);
	write(fd, bmp_head, 14);
	write(fd, bmp_fhead, 40);
	size = all->mlx->bpp / 8 * all->cub->resolution.width;
	i = -1;
	while (++i < all->cub->resolution.height)
		write(fd, all->mlx->addr + i * all->mlx->line_l, size);
	return (0);
}

int			ft_get_screenshot(t_all *all)
{
	unsigned char	bmp_head[14];
	unsigned char	bmp_fhead[40];
	int				res;

	res = 0;
	ft_putstr("--> MAKE SCREENSHOT\n");
	ft_bzero(bmp_head, 14);
	ft_bzero(bmp_fhead, 40);
	res = ft_make_head(bmp_head, bmp_fhead, all);
	res = (res != -1 ? ft_make_file_scr(bmp_head, bmp_fhead, all) : res);
	res = (res == -1 ? ft_putstr_fd("--> ERROR IN SCREENSHOT\n", 2) : res);
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	ft_putstr("--> SCREENSHOT DONE\n");
	exit(0);
	return (0);
}

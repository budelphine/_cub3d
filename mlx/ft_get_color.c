/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:12:46 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 16:10:40 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned long	ft_get_color(t_xpm *tmp, t_plr *plr, int tex_x, int tex_y)
{
	if (tex_x < 0 || tex_x >= tmp->width || tex_y < 0 || tex_y >= tmp->height)
		return (0);
	plr->color = (*(unsigned long *)(tmp->addr + \
				(tex_y * tmp->line_l + tex_x * (tmp->bpp / 8))));
	return (plr->color);
}

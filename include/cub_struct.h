/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:23:36 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/13 23:01:59 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

/*
**	Универсальная структура для передачи цвета в rgb
*/

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

/*
**	Разрешение экрана - ширина и высота
*/

typedef struct		s_resolution
{
	int				height;
	int				width;
}					t_resolution;

/*
**	Путь ко всем спрайтам
*/

typedef struct		s_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*spr;
}					t_path;

/*
**	Структура куда парсится карта из файла .cub
*/

typedef struct		s_cub
{
	t_resolution	resolution;
	t_path			path;
	t_rgb			floor;
	t_rgb			sky;
	char			**map;
	int				screen;
}					t_cub;

/*
** Структура для работы с mlx и окнами
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bpp;
	int				line_l;
	int				enn;
}					t_mlx;

/*
** Структура игрока
*/

typedef struct		s_plr
{
	double			cam_x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			plane_x;
	double			plane_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wall_dist;
	int				h;
	int				line_h;
	int				draw_s;
	int				draw_e;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	double			wall_x;
	unsigned long	color;
}					t_plr;

/*
** Структура для текстурирования (?)
*/

typedef struct		s_xpm
{
	void			*img;
	void			*addr;
	char			*path;
	int				width;
	int				height;
	int				bpp;
	int				line_l;
	int				enn;
}					t_xpm;

/*
** Структура для работы с текстурами
*/

typedef struct		s_tex
{
	t_xpm			no;
	t_xpm			so;
	t_xpm			we;
	t_xpm			ea;
	t_xpm			spr;
}					t_tex;

/*
** Структура для работы со спрайтами
*/

typedef struct		s_spr_arr
{
	double			dist;
	double			x;
	double			y;
	int				num;
}					t_spr_arr;

/*
** Для работы со спрайтами
*/

typedef struct		s_spr
{
	t_spr_arr		*arr;
	double			spr_x;
	double			spr_y;
	double			inv_det;
	double			ts_x;
	double			ts_y;
	int				cur;
	int				max;
	int				tex_x;
	int				tex_y;
	int				screen_x;
	int				vmove_screen;
	int				height;
	int				width;
	int				draw_sx;
	int				draw_sy;
	int				draw_ex;
	int				draw_ey;
	int				stripe;
	int				d;
	int				y;
}					t_spr;

/*
**	Структура с указателями на все структуры
*/

typedef struct		s_all
{
	t_cub			*cub;
	t_mlx			*mlx;
	t_plr			*plr;
	t_tex			*tex;
	t_spr			*spr;
	char			**map;
	int				x;
}					t_all;

#endif

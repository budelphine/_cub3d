/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:43:52 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/14 01:15:01 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FUNC_H
# define CUB_FUNC_H

/*
** Подключение стандартных библиотек
*/

# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Подключение собственных библиотек
*/

# include "get_next_line.h"
# include "../libft/libft.h"
# include "cub_struct.h"

/*
** MAIN
*/

int				ft_cub3d(int ac, char **av);
void			ft_get_start_value(int x, double s_width, t_plr *plr);
void			ft_get_delta_dist(t_plr *plr);
void			ft_get_side_dist_and_step(t_plr *plr);
void			ft_get_dda(t_all *all, t_plr *plr);
void			ft_get_wall_draw_start(t_plr *plr, int s_height);
void			ft_draw_sky_and_floor(t_all *all, t_plr *plr);
void			ft_get_textured_wall(t_all *all, t_plr *plr);
void			ft_init_sprite_arr(t_all *all, t_spr_arr arr[], int i);
void			ft_draw_sprites(t_all *all, t_plr *plr, \
				t_spr *spr, double z_buf[]);

/*
** INIT_STRUCT
*/

t_rgb			ft_make_rgb_struct(int r, int g, int b);
int				ft_init_cub_struct(t_cub *cub);
int				ft_init_all_struct(t_all *all);
void			ft_init_plr_struct(t_all *all, t_plr *plr);
void			ft_init_all(t_all *all);
int				ft_init_tex_struct(t_all *all, void *mlx, t_tex *tex);
void			ft_init_spr_struct(t_all *all, t_spr *spr);

/*
** PARSER
*/

int				ft_parser(int ac, char **av, t_cub *cub);
int				ft_parse_cub(int fd, t_cub *cub);
int				ft_parse_cub_elem(char *line, t_cub *cub, int fd);
int				ft_parse_cub_resolution(char **line, t_cub *cub);
int				ft_parse_cub_sprite(char **line, t_cub *cub, char *ch);
int				ft_parse_cub_color(char **line, t_cub *cub);
int				ft_parse_cub_map(char **line, t_cub *cub, int fd);

/*
** VALIDATOR
*/

int				ft_is_valid(t_cub *cub);
int				ft_is_valid_resolution(t_cub *cub);
int				ft_is_valid_sprite(t_cub *cub);
int				ft_is_valid_color(t_cub *cub);
int				ft_is_valid_map(t_cub *cub);
char			**ft_create_new_array(char **map);

/*
** MLX
*/

void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int				ft_get_mlx(t_mlx *mlx, t_cub *cub);
int				ft_hook_press_key(int key, t_all *all);
unsigned long	ft_get_color(t_xpm *tmp, t_plr *plr, int tex_x, int tex_y);

/*
** CUB3D
*/

int				ft_cub_2d(t_all *all);
int				ft_render_cub(t_plr *plr, t_all *all);

/*
** UTILS
*/

int				ft_get_screenshot(t_all *all);
int				ft_check_file_ext(char *file_name, char *ext);

void			ft_move_spaces(char **line);
void			ft_move_non_spaces(char **line);
int				ft_move_digit(char **line);

int				ft_is_map_key(char ch);
int				ft_is_wall(char ch);
int				ft_is_spawn(char ch);
int				ft_is_empty_line(char *line);

int				ft_strlen_y(char **map);

/*
** FREE
*/

void			*ft_remove_arr(char **arr, int i_current);
int				ft_free_cub(t_cub *cub);

#endif

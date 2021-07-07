# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 18:59:47 by budelphi          #+#    #+#              #
#    Updated: 2021/02/14 01:34:52 by budelphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * SOURCE FILE - HEADER && FT.C && FT.O

NAME	=	cub3D

INC		=	include
HEADER	= 	include/get_next_line.h \
			include/cub_func.h \
			include/cub_struct.h \
			include/cub3d.h

SRCS	=	main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			base/ft_cub3d.c \
			parser/ft_parser.c \
			parser/ft_parse_cub.c \
			parser/ft_parse_cub_elem.c \
			parser/ft_parse_cub_resolution.c \
			parser/ft_parse_cub_sprite.c \
			parser/ft_parse_cub_color.c \
			parser/ft_parse_cub_map.c \
			validator/ft_is_valid.c \
			validator/ft_is_valid_color.c \
			validator/ft_is_valid_resolution.c \
			validator/ft_is_valid_sprite.c \
			validator/ft_is_valid_map.c \
			validator/ft_create_new_array.c \
			mlx/ft_get_mlx.c \
			mlx/my_mlx_pixel_put.c \
			mlx/ft_hook_press_key.c \
			mlx/ft_get_color.c \
			init/ft_init_all_struct.c \
			init/ft_init_all.c \
			init/ft_init_cub_struct.c \
			init/ft_init_spr_struct.c \
			init/ft_init_plr_struct.c \
			init/ft_init_tex_struct.c \
			cub/cub_2d.c \
			cub/ft_render_cub.c \
			cub/ft_draw_sky_and_floor.c \
			cub/ft_get_dda.c \
			cub/ft_get_delta_dist.c \
			cub/ft_get_side_dist_and_step.c \
			cub/ft_get_start_value.c \
			cub/ft_get_wall_draw_start.c \
			cub/ft_get_textured_wall.c \
			cub/ft_draw_sprites.c \
			cub/ft_init_sprite_arr.c \
			utils/ft_get_screenshot.c \
			utils/ft_check_file_ext.c \
			utils/ft_move_line.c \
			utils/ft_is_symbol.c \
			utils/ft_strlen_y.c \
			free/ft_remove_arr.c \
			free/ft_free_cub.c

OBJ		=	$(SRCS:.c=.o)

# DEFINE FUNCTION GCC, FLAGS, AR, RM

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs

RM		=	rm -f

# INIT OPENGL AND LIBFT LIB

LIB_MLX		=	./opengl -lmlx -framework OpenGL -framework Appkit
LIB_FT		=	./libft -lft

ADD_LIBS	=	-L$(LIB_MLX) -L$(LIB_FT)

# * LIBFT SOURCE TO DEPENDENCIES

LIBFTA		=	libft/libft.a

LIBFT_HEAD	=	libft/libft.h

LIBFT_SRCS	=	libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_memccpy.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_strdel.c \
				libft/ft_putstr.c \
				libft/ft_lstnew.c \
				libft/ft_lstadd_front.c \
				libft/ft_lstsize.c \
				libft/ft_lstlast.c \
				libft/ft_lstadd_back.c \
				libft/ft_lstdelone.c \
				libft/ft_lstclear.c \
				libft/ft_lstiter.c \
				libft/ft_lstmap.c

OBJS_LIBFT		= $(LIBFT_SRCS:.c=.o)

MAKE_LIBFT	=	make bonus -C ./libft

#  * OPENGL SOURCE TO DEPENDENCIES

OPENGLA		=	opengl/libmlx.a

OPENGL_HEAD	=	opengl/mlx_int.h \
				opengl/mlx_new_window.h \
				opengl/mlx_opengl.h \
				opengl/mlx_png.h \
				opengl/mlx.h 

OPENGL_SRCS =	opengl/mlx_xpm.c \
				opengl/mlx_png.c \
				opengl/mlx_shaders.c \
				opengl/mlx_int_str_to_wordtab.c \
				opengl/mlx_new_window.m \
				opengl/mlx_init_loop.m \
				opengl/mlx_new_image.m \
				opengl/mlx_mouse.m

OPENGL_OBJ_ADD	=	$(SRC:.c=.o)
OPENGL_OBJ_ALL	=	$(OBJ_ADD:.m=.o)

MAKE_OPENGL	=	make -C ./opengl

# TODO: START COMPILE PROJECT

all:		
			$(MAKE) $(NAME) -j 4

$(NAME):	$(OBJ) $(HEADER) $(LIBFTA) $(OPENGLA)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(ADD_LIBS)

.c.o:
			$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

# TODO: END COMPILE PROJECT

# * DEPENDENCIES TO LIBFT

$(LIBFTA):	$(OBJS_LIBFT) $(LIBFT_HEAD)
			$(MAKE_LIBFT)

# * DEPENDENCIES TO LIBFT

$(OPENGL_OBJ_ALL):	$(OPENGL_HEAD)

$(OPENGLA):	$(OPENGL_OBJ_ALL)
			$(MAKE_OPENGL)

# * START CUSTOM AND DEFAULT MAP

MAP_CUSTOM		=	map/map_custom.cub
MAP_DEFAULT		=	map/map_default.cub

custom:		
			./$(NAME) $(MAP_CUSTOM)

default:		
			./$(NAME) $(MAP_DEFAULT)

# * clean, fclean, re

CLEAN_OPENGL	=	make clean -C ./opengl
CLEAN_LIBFT		=	make clean -C ./libft
FCLEAN_LIBFT	=	make fclean -C ./libft

clean:
			$(RM) $(OBJ)
			$(RM) $(INC)/*.gch
			$(CLEAN_OPENGL)
			$(CLEAN_LIBFT)

fclean:		clean
			$(FCLEAN_LIBFT)
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
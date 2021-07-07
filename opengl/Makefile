#
#

NAME	=	libmlx.a

SRC		=	mlx_xpm.c \
			mlx_png.c \
			mlx_shaders.c \
			mlx_int_str_to_wordtab.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_mouse.m

OBJ_ADD	=	$(SRC:.c=.o)
OBJ_ALL	=	$(OBJ_ADD:.m=.o)

CFLAGS	+=	-O2

# add to match string put with X11 in size and position
CFLAGS	+=	-DSTRINGPUTX11

all:		$(NAME)

$(NAME):	$(OBJ_ALL)
			ar -r $(NAME) $(OBJ_ALL)
			ranlib $(NAME)

clean:
			rm -f $(NAME) $(OBJ_ALL) *~
			rm -f mlx_app

re:	clean all

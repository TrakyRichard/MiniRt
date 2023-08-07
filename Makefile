NAME	= miniRT

INCLDIR	= includes/
LIB = libs/

SRCDIR	= srcs/
COLORDIR = color/
RAYDIR = ray/
VECDIR = vec/
PARSERDIR = parser/
UTILS = utils/
INTERSECTION = intersection/
SHAPE = shape/
RENDER = render/

SRCFILES=	$(COLORDIR)col_ops.c				\
			$(COLORDIR)col_utils.c				\
			$(COLORDIR)col_inits.c				\
			$(COLORDIR)col_utils_2.c			\
			$(VECDIR)vec_ops.c					\
			$(VECDIR)vec_utils.c				\
			$(VECDIR)vec_utils_2.c				\
			$(VECDIR)vec_inits.c				\
			$(RAYDIR)ray.c						\
			$(RAYDIR)get_shape_ray.c			\
			$(RAYDIR)get_shape_ray_2.c			\
			$(PARSERDIR)parser.c				\
			$(PARSERDIR)parse_elmts_2.c			\
			$(PARSERDIR)parse_elmts.c			\
			$(UTILS)error.c						\
			$(UTILS)shapes_func.c				\
			$(UTILS)shapes_ops.c				\
			$(UTILS)open.c						\
			$(UTILS)utils.c						\
			$(UTILS)utils2.c					\
			$(UTILS)init.c						\
			$(UTILS)mlx.c						\
			$(INTERSECTION)intersection.c		\
			$(INTERSECTION)intersection_2.c		\
			$(INTERSECTION)init_intersections.c	\
			$(INTERSECTION)set_intersections.c	\
			$(SHAPE)shape_intersect.c			\
			$(SHAPE)does_shape_intersect.c		\
			$(RENDER)render.c					\
			$(RENDER)light.c					\
			$(RENDER)utils.c					\
			main.c


# INCLFILES=	srcs/parser/parser.h	\
# 			libs/libmlx/mlx.h 		\
# 			srcs/color/col.h		\
# 			srcs/ray/ray.h			\
# 			srcs/vec/vec.h			\
# 			srcs/minirt.h			\
# 			srcs/render/render.h	\


SRCS	= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS	= $(SRCS:.c=.o)
CC		= gcc -g3
RM		= rm -f

CFLAGS	=-DTHREADS=$(THREADS) -g3 -Wall -Wextra -fsanitize=address -Werror -Ofast -O0
FLAGS = -L $(LIB)libft -lft -L $(LIB)libmlx -lmlx

MACOS_MACRO = -DMACOS
LINUX_MACRO = -DLINUX
MACOS_FLAGS	= -framework OpenGL -framework AppKit
LINUX_FLAGS = -lm -lX11 -lXext -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

all:		$(NAME)

$(NAME) : compilelibft compilelibmlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

compilelibft:
	make -C $(LIB)libft all

compilelibmlx:
	make -C $(LIB)libmlx all

cleanlibft:
	make -C $(LIB)libft clean

cleanlibmlx:
	make -C $(LIB)libmlx clean

fcleanlibft:
	make -C $(LIB)libft fclean

fcleanlibmlx:
	make -C $(LIB)libmlx clean

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

clean:	cleanlibft cleanlibmlx
			$(RM) $(OBJS)

fclean:	clean fcleanlibft fcleanlibmlx
			$(RM) $(NAME)

re:			fclean all

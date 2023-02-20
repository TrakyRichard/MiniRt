NAME	= miniRT

INCLDIR	= includes/

SRCDIR	= srcs/

LIB = includes/

SRCFILES=	color.c					\
			error.c					\
			main.c					\
			make_img.c				\
			parse.c					\
			ray.c					\
			save_bmp.c				\
			set_elements.c			\
			set_elements2.c			\
			utils.c					\
			vector.c				\


INCLFILES=	minirt.h		\

SRCS	= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS	= $(SRCS:.c=.o)
INCLS	= $(addprefix $(INCLDIR), $(INCLFILES))
CC		= gcc -g
RM		= rm -f

CFLAGS	= -I $(INCLDIR) -DTHREADS=$(THREADS) -Wall -Wextra -fsanitize=address -g3#-Werror -Ofast
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

$(NAME) : compilelibft compilelibmlx $(OBJS) $(INCLS)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

all:		$(NAME)

compilelibft :
	make -C $(LIB)libft all

compilelibmlx :
	make -C $(LIB)libmlx all

%.o: %.c $(INCLS)
	$(CC) $(CFLAGS) -c -I $(INCLDIR) -o $@ $<


clean:
			make clean -C $(LIB)libft
			# make clean -C $(LIB)libvector
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIB)libft
			# make fclean -C $(LIB)libvector
			$(RM) $(NAME)

re:			fclean all


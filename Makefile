NAME	= miniRT

INCLDIR	= includes/
LIB = libs/

SRCDIR	= srcs/
COLORDIR = color/
RAYDIR = ray/
VECDIR = vec/

SRCFILES=	$(COLORDIR)col_ops.c		\
			$(COLORDIR)col_utils.c		\
			$(COLORDIR)col_inits.c		\
			$(VECDIR)vec_ops.c			\
			$(VECDIR)vec_utils.c		\
			$(VECDIR)vec_inits.c		\
			$(RAYDIR)ray.c				\
			render.c					\
			richard.c					\
			init.c


SRCS	= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS	= $(SRCS:.c=.o)
CC		= gcc -g3
RM		= rm -f

CFLAGS	=-DTHREADS=$(THREADS) -g3 -Wall -Wextra -fsanitize=address -Werror -Ofast
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


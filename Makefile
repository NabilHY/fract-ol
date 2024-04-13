CC = cc
FLAGS = -Wall -Wextra -Werror
ENTRY = fractol.c
SRCS = 	./srcs/math_utils.c \
./srcs/fractal_render.c \
./srcs/fractal_init.c
OBJS = $(SRCS:.c=.o)
LIB_AR = ./libr/libr.a
LIB_INLUDE = ./libr/libr.h
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ./MLX42/include/MLX42.h
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
GLFW_PATH = /users/nhayoun/.brew/opt/glfw/lib/
MLX_AR = ./MLX42/build/libmlx42.a
MLXLIB = ./MLX42/lib/MLX42
FSANITIZE= -g -fsanitize=address
NAME = fractol

.PHONY: libr

all: $(NAME)

$(LIB_AR):
	make -C libr

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIB_AR) $(MLX_AR)
	$(CC) $(FLAGS) $(OBJS) $(ENTRY) $(LIB_AR) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)

$(LIB_NAME):
	make -C libr
lib_clean:
	make clean -C libr
lib_fclean: lib_clean
	make fclean -C libr
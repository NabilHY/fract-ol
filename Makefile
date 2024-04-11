CC = cc
FLAGS = -Wall -Wextra -Werror
ENTRY = fractol.c
SRCS = ./srcs/fractal_init.c
OBJS = $(SRCS:./objs/.o=.c)
LIB_AR = ./libr/libr.a
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

$(NAME):  $(LIB_AR) $(MLX_AR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(ENTRY) $(LIB_AR) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)

./objs/%.o: %.c
	mkdir -p objs
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

$(LIB_NAME):
	make -C libr
lib_clean:
	make clean -C libr
lib_fclean: lib_clean
	make fclean -C libr
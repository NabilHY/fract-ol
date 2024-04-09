CC = cc
FLAGS = -Wall -Wextra -Werror
ENTRY = fractol.c
OBJS = $(SRCS:objs/.o=.c)
LIB_AR = ./libr/libr.a
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ./mlx/include/MLX42.h
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
GLFW_PATH = /users/nhayoun/.brew/opt/glfw/lib/
MLX_AR = ./mlx/build/libmlx42.a
MLXLIB = ./mlx/lib/MLX42
FSANITIZE= -g -fsanitize=address
NAME = fractol

.PHONY: libr

all: $(NAME)

$(LIB_AR):
	make -C libr

$(NAME):
	$(CC) $(FLAGS) $(ENTRY) $(LIB_AR) $(MLX_MACOS) $(MLX_AR) $(GLFW)   -o $(NAME)

./objs/%.o: %.c
	mkdir -p objs
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

$(LIB_NAME):
	make -C libr
lib_clean:
	make clean -C libr
lib_fclean: lib_clean
	make fclean -C libr

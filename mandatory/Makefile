CC = cc
FLAGS = -Wall -Wextra -Werror
ENTRY = fractol.c
SRCS = 	./srcs/math_utils.c \
./srcs/fractal_render.c \
./srcs/fractal_init.c	\
./srcs/parsing_utils.c
OBJS = $(SRCS:.c=.o)
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

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIB_AR) $(MLX_AR)
	$(CC) $(FLAGS) $(OBJS) $(ENTRY) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)

$(LIB_NAME):
	make -C libr
clean:
	rm -rf ./srcs/*.o
fclean: clean
	rm -rf ./fractol
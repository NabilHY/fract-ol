cc = CC
FLAGS = -Wall -Wextra -Werror -O3
ENTRY = fractol.c
SRCS =	./srcs/math_utils.c \
./srcs/fractal_render.c \
./srcs/fractal_init.c	\
./srcs/parsing_utils.c \
./srcs/utils.c
INCLUDE = fractol.h
OBJS = $(SRCS:%.c=%.o)
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ../MLX42/include/MLX42.h
MLX_AR = ../MLX42/build/libmlx42.a
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
NAME = ../fractol

%.o: %.c $(INCLUDE)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@

$(NAME): $(MLX_AR) $(OBJS) $(INCLUDE) 
	@$(CC) $(FLAGS) $(OBJS) -I$(INCLUDE) $(ENTRY) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)
	@echo "Program Compiled successfully."

clean:
	rm -rf $(OBJS)
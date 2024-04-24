cc = CC
FLAGS = -Wall -Wextra -Werror -O3
ENTRY = fractol_bonus.c
SRCS = ./srcs/fractal_init_bonus.c \
./srcs/fractal_render_bonus.c \
./srcs/math_utils_bonus.c \
./srcs/utils_bonus.c \
./srcs/parsing_utils_bonus.c \
./srcs/fractals_events_bonus.c
INCLUDE = fractol_bonus.h
OBJS = $(SRCS:%.c=%.o)
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ../MLX42/include/MLX42.h
MLX_AR = ../MLX42/build/libmlx42.a
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
NAME = ../fractol_bonus

%.o: %.c $(INCLUDE)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@
$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(FLAGS) $(OBJS) -I$(INCLUDE) $(ENTRY) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)
	@echo "Program Compiled successfully."
clean:
	rm -rf $(OBJS)

CC = cc
FLAGS = -Wall -Wextra -Werror -O3
ENTRY = ./mandatory/fractol.c
ENTRY_BON = ./bonus/fractol_bonus.c
SRCS =	./mandatory/srcs/math_utils.c \
./mandatory/srcs/fractal_render.c \
./mandatory/srcs/fractal_init.c	\
./mandatory/srcs/parsing_utils.c \
./mandatory/srcs/utils.c
SRCS_BON = ./bonus/srcs/fractal_init_bonus.c \
./bonus/srcs/fractal_render_bonus.c \
./bonus/srcs/math_utils_bonus.c \
./bonus/srcs/utils_bonus.c \
./bonus/srcs/parsing_utils_bonus.c \
./bonus/srcs/fractals_events_bonus.c
OBJS = $(SRCS:%.c=%.o)
OBJS_BON = $(SRCS_BON:%.c=%.o)
INCLUDE = ./mandatory/fractol.h
INCLUDE_BON = ./bonus/fractol_bonus.h
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ./MLX42/include/MLX42.h
MLX42_DIR = ./MLX42
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
MLX_AR = ./MLX42/build/libmlx42.a
MLXLIB = ./MLX42/lib/MLX42
FSANITIZE= -g -fsanitize=address
NAME = fractol
NAME_BON = fractol_bonus

all: $(MLX_AR) $(NAME)

bonus : $(MLX_AR) $(NAME_BON)

$(MLX42_DIR):
	@echo "Cloning MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42.git > /dev/null 2>&1
	@echo "MLX42 has been successfully cloned."

$(MLX_AR): $(MLX42_DIR)
	@echo "Building MLX42..."
	@git submodule update --init --recursive
	@cd MLX42 && cmake -B build && cmake --build build -j4 > /dev/null 2>&1
	@echo "MLX42 has been successfully built." > /dev/null 2>&1

$(NAME): $(INCLUDE) $(OBJS)
	make -C mandatory
$(NAME_BON): $(INCLUDE_BON) $(OBJS_BON)
	make -C bonus
clean:
	make clean -C mandatory
	make clean -C bonus
fclean: clean
	rm -rf $(NAME) $(NAME_BON)
re: fclean all
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
./bonus/srcs/fractals_events.c


OBJS = $(SRCS:.c=.o)
OBJS_BON = $(SRCS_BON:.c=.o)
MLX_MACOS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE = ./MLX42/include/MLX42.h
MLX42_DIR = ./MLX42
GLFW = -lglfw -L/Users/nhayoun/.brew/opt/glfw/lib/
GLFW_PATH = /users/nhayoun/.brew/opt/glfw/lib/
MLX_AR = ./MLX42/build/libmlx42.a
MLXLIB = ./MLX42/lib/MLX42
FSANITIZE= -g -fsanitize=address
NAME = fractol
NAME_BON = fractol_bonus

all: $(MLX_AR) $(NAME)

bonus : $(NAME_BON)

$(MLX42_DIR):
	@echo "Cloning MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42.git > /dev/null 2>&1
	@echo "MLX42 has been successfully cloned."

$(MLX_AR): $(MLX42_DIR)
	@echo "Building MLX42..."
	@git submodule update --init --recursive
	@cd MLX42 && cmake -B build && cmake --build build -j4 > /dev/null 2>&1
	@echo "MLX42 has been successfully built." > /dev/null 2>&1

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@

$(NAME): $(MLX_BUILD) $(OBJS) $(INCLUDE)
	@$(CC) $(FLAGS) $(OBJS) $(ENTRY) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME)
	@echo "Fractol has been successfully built."

$(NAME_BON): $(MLX_BUILD) $(OBJS_BON) $(INCLUDE)
	@$(CC) $(FLAGS) $(OBJS_BON) $(ENTRY_BON) $(MLX_MACOS) $(MLX_AR) $(GLFW) -o $(NAME_BON)
	@echo "Program Compiled successfully."


clean:
	rm -rf $(OBJS) $(OBJS_BON)
fclean: clean
	rm -rf $(NAME) $(NAME_BON)
re: fclean all
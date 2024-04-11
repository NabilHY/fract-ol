CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./ft_printf/srcs/ft_print_hex.c \
./ft_printf/srcs/ft_print_int.c \
./ft_printf/srcs/ft_print_ptr.c \
./ft_printf/srcs/ft_print_str.c \
./ft_printf/ft_printf.c
SRCS_LIBFT = ./ft_printf/libft/ft_isascii.c \
./ft_printf/libft/ft_isalpha.c \
./ft_printf/libft/ft_isdigit.c \
./ft_printf/libft/ft_isprint.c \
./ft_printf/libft/ft_isalnum.c \
./ft_printf/libft/ft_strlen.c \
./ft_printf/libft/ft_memset.c \
./ft_printf/libft/ft_bzero.c \
./ft_printf/libft/ft_memcpy.c \
./ft_printf/libft/ft_memmove.c \
./ft_printf/libft/ft_strlcpy.c \
./ft_printf/libft/ft_strlcat.c \
./ft_printf/libft/ft_toupper.c \
./ft_printf/libft/ft_tolower.c \
./ft_printf/libft/ft_strchr.c \
./ft_printf/libft/ft_strrchr.c \
./ft_printf/libft/ft_strncmp.c \
./ft_printf/libft/ft_memchr.c \
./ft_printf/libft/ft_memcmp.c \
./ft_printf/libft/ft_strnstr.c \
./ft_printf/libft/ft_atoi.c \
./ft_printf/libft/ft_itoa.c \
./ft_printf/libft/ft_calloc.c \
./ft_printf/libft/ft_strdup.c \
./ft_printf/libft/ft_substr.c \
./ft_printf/libft/ft_strjoin.c \
./ft_printf/libft/ft_strtrim.c \
./ft_printf/libft/ft_split.c \
./ft_printf/libft/ft_striteri.c \
./ft_printf/libft/ft_strmapi.c \
./ft_printf/libft/ft_putchar_fd.c \
./ft_printf/libft/ft_putstr_fd.c \
./ft_printf/libft/ft_putnbr_fd.c \
./ft_printf/libft/ft_putendl_fd.c \
./ft_printf/libft/ft_lstnew_bonus.c \
./ft_printf/libft/ft_lstadd_front_bonus.c \
./ft_printf/libft/ft_lstsize_bonus.c \
./ft_printf/libft/ft_lstlast_bonus.c \
./ft_printf/libft/ft_lstadd_back_bonus.c \
./ft_printf/libft/ft_lstdelone_bonus.c \
./ft_printf/libft/ft_lstclear_bonus.c \
./ft_printf/libft/ft_lstiter_bonus.c \
./ft_printf/libft/ft_lstmap_bonus.c
SRCS_GNL = ./get_next_line/get_next_line_utils.c \
./get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o)
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
NAME = libr.a
INCLUDE = libr.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(INCLUDE) $(OBJS) $(OBJS_LIBFT) $(OBJS_GNL)
	printf "$(NAME) Archive Created"
	@ar rcs $(NAME) $(OBJS) $(OBJS_LIBFT) $(OBJS_GNL)

%.o: %.c 
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_LIBFT)
	@rm -rf $(OBJS_GNL)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

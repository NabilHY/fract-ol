CC = cc
FLAGS = -Wall -Wextra -Werror
LIB_AR = ./libr/libr.a
FSANITIZE= -g -fsanitize=address
LIB_NAME = libr.a

.PHONY: libr

all: $(LIB_NAME)

$(LIB_NAME):
	make -C libr
lib_clean:
	make clean -C libr
lib_fclean: lib_clean
	make fclean -C libr

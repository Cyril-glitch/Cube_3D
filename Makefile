NAME = bin/cube3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g2
OBJ_DIR = obj
BIN_DIR = bin

UNAME_S := $(shell uname -s)

LIBDIR = ./libft/
LIB = $(LIBDIR)lib/libft.a
MLX_DIR = ./minilibx-linux/

# MiniLibX 
MLX_LIB_FILE = $(MLX_DIR)libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz

MAIN_SRC = src/main.c

INIT_SRC = src/init_src/init.c

GAME_EXIT_SRC = src/cleanup_src/game_exit.c

SRC = $(MAIN_SRC) $(INIT_SRC) $(GAME_EXIT_SRC)
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX_LIB_FILE)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX_LIB_FILE) $(MLX_FLAGS) $(MLX_INC) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(LIB):
	make -C $(LIBDIR)

$(MLX_LIB_FILE):
	-make -C $(MLX_DIR)

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBDIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all
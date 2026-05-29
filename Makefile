NAME = bin/cube3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
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

CLEAN_UP_SRC = src/cleanup_src/game_exit.c \
			   src/cleanup_src/memory_cleaner.c

PARSER_SRC = src/parser_src/gnl_no_nl.c \
			 src/parser_src/gnl.c \
		 	 src/parser_src/parse_assets.c \
		 	 src/parser_src/parse_color.c \
		 	 src/parser_src/parse_map.c \
		 	 src/parser_src/parse_texture.c \
		 	 src/parser_src/parser.c \
		 	 src/parser_src/parser_utils.c \
		 	 src/parser_src/parse_map_utils.c \
		 	 src/parser_src/parse_map_utils_2.c 

SRC = $(MAIN_SRC) $(INIT_SRC) $(CLEAN_UP_SRC) $(PARSER_SRC)
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

start:	all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/cube3d config/map.cub

lldb : all
	lldb ./bin/cube3d config/map.cub

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBDIR)
	make clean -C $(MLX_DIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -rf $(BIN_DIR)

re: fclean all
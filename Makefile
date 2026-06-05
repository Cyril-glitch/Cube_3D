NAME = bin/cube3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Wno-incompatible-pointer-types
OBJ_DIR = obj
BIN_DIR = bin

UNAME_S := $(shell uname -s)

LIBDIR = ./libft/
LIB = $(LIBDIR)lib/libft.a
MLX_DIR = ./minilibx-linux

# MiniLibX 
MLX_LIB_FILE = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz

MAIN_SRC = src/main.c

INIT_SRC = src/init_src/init.c \
		   src/init_src/mini_map_init.c

CLEAN_UP_SRC = src/cleanup_src/game_exit.c \
			   src/cleanup_src/memory_cleaner.c \
			   src/cleanup_src/utils.c

UPDATE_SRC = src/update/hooks.c \
			 src/update/move.c \
			 src/update/rotate.c \
			 src/update/update.c

RENDER_SRC = src/render_src/mini_map_draw.c \
			 src/render_src/pixel_management_1.c \
			 src/render_src/pixel_management_2.c \
			 src/render_src/raycasting.c \
			 src/render_src/render_draw.c \
			 src/render_src/trgb.c \
			 src/render_src/render_fc.c

PARSER_SRC = src/parser_src/gnl_no_nl.c \
			 src/parser_src/gnl.c \
			 src/parser_src/parse_assets.c \
		 	 src/parser_src/parse_color.c \
		 	 src/parser_src/parse_color_utils.c \
		 	 src/parser_src/parse_map.c \
		 	 src/parser_src/parse_texture.c \
		 	 src/parser_src/parser.c \
		 	 src/parser_src/parser_utils.c \
			 src/parser_src/map_checker.c \
		 	 src/parser_src/map_checker_utils_2.c \
             src/parser_src/map_checker_utils.c \
			 src/parser_src/extract_map.c

GAME_SRC = 	 src/game_src/game.c



SRC = $(MAIN_SRC) $(INIT_SRC) $(CLEAN_UP_SRC) $(PARSER_SRC) $(UPDATE_SRC) $(RENDER_SRC) $(GAME_SRC)
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

it:
	./bin/cube3d config/map.cub

gdb : all
	gdb ./bin/cube3d

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -rf $(BIN_DIR)

re: fclean all
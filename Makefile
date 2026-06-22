NAME = bin/cube3d
BONUS = bin/cube3d_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g3 -Wno-incompatible-pointer-types
OBJ_DIR = obj
BIN_DIR = bin

UNAME_S := $(shell uname -s)

LIBDIR = ./libft/
LIB = $(LIBDIR)lib/libft.a
MLX_DIR = ./minilibx-linux

# MiniLibX 
MLX_LIB_FILE = $(MLX_DIR)/lib/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz

MAIN_SRC = src/main.c

INIT_SRC = src/init_src/data_init.c \
		   src/init_src/mini_map_init.c \
		   src/init_src/texture_init.c \
		   src/init_src/mlx_init.c \
		   src/init_src/doors_init.c \
		   src/init_src/sprites_init.c \
		   src/init_src/init_monsters.c \
		   src/init_src/offsets_init.c \
		   src/init_src/init_mandatory.c\
		   src/init_src/bfs_init.c  


CLEAN_UP_SRC = src/cleanup_src/game_exit.c \
			   src/cleanup_src/free_texture.c \
			   src/cleanup_src/memory_cleaner.c 

UPDATE_SRC = src/update/hooks_mandatory.c \
			 src/update/move.c \
			 src/update/rotate.c \
			 src/update/update_mandatory.c \
			 src/update/bfs.c \
			 src/update/bfs_utils.c \
			 src/update/set_bfs.c \
			 src/update/get_target_path.c \
			 src/update/get_next_step.c \
			 src/update/damage.c \
			 src/update/healing.c \
			 src/update/winning.c \
			 src/update/bot_move.c \
			 src/update/player_stats.c



RENDER_SRC = src/render_src/mini_map_draw.c \
			 src/render_src/draw_sprites.c \
			 src/render_src/pixel_management_1.c \
			 src/render_src/pixel_management_2.c \
			 src/render_src/raycasting.c \
			 src/render_src/render_mandatory.c \
			 src/render_src/render_utils.c \
			 src/render_src/trgb.c \
			 src/render_src/render_fc.c \
			 src/render_src/render_ath.c \
			 src/render_src/render_death.c \
			 src/render_src/render_win.c \
			 src/render_src/draw_health.c 

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
             src/parser_src/map_checker_utils_mandatory.c \
			 src/parser_src/extract_map.c

GAME_SRC = 	 src/game_src/game.c

MAIN_SRC_BONUS = src/main.c

INIT_SRC_BONUS = src/init_src/data_init.c \
		   src/init_src/mini_map_init.c \
		   src/init_src/texture_init.c \
		   src/init_src/mlx_init.c \
		   src/init_src/doors_init.c \
		   src/init_src/sprites_init.c \
		   src/init_src/init_monsters.c \
		   src/init_src/offsets_init.c \
		   src/init_src/init.c\
		   src/init_src/bfs_init.c  


CLEAN_UP_SRC_BONUS = src/cleanup_src/game_exit.c \
			   		 src/cleanup_src/memory_cleaner.c \
			   		 src/cleanup_src/free_texture.c

UPDATE_SRC_BONUS = src/update/hooks.c \
			 src/update/move.c \
			 src/update/rotate.c \
			 src/update/update.c \
			 src/update/bfs.c \
			 src/update/bfs_utils.c \
			 src/update/set_bfs.c \
			 src/update/get_target_path.c \
			 src/update/get_next_step.c \
			 src/update/bot_move.c \
			 src/update/damage.c \
			 src/update/winning.c \
			 src/update/healing.c \
			 src/update/player_stats.c

RENDER_SRC_BONUS = src/render_src/mini_map_draw.c \
			 src/render_src/draw_sprites.c \
			 src/render_src/pixel_management_1.c \
			 src/render_src/pixel_management_2.c \
			 src/render_src/raycasting.c \
			 src/render_src/render.c \
			 src/render_src/render_utils.c \
			 src/render_src/trgb.c \
			 src/render_src/render_fc.c \
			 src/render_src/render_ath.c \
			 src/render_src/render_win.c \
			 src/render_src/render_death.c \
			 src/render_src/draw_health.c 

PARSER_SRC_BONUS = src/parser_src/gnl_no_nl.c \
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

GAME_SRC_BONUS = 	 src/game_src/game.c

SRC = $(MAIN_SRC) $(INIT_SRC) $(CLEAN_UP_SRC) $(PARSER_SRC) $(UPDATE_SRC) $(RENDER_SRC) $(GAME_SRC)
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

SRC_BONUS = $(MAIN_SRC_BONUS) $(INIT_SRC_BONUS) $(CLEAN_UP_SRC_BONUS) $(PARSER_SRC_BONUS) $(UPDATE_SRC_BONUS) $(RENDER_SRC_BONUS) $(GAME_SRC_BONUS)
OBJ_BONUS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC_BONUS))

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ) $(LIB) $(MLX_LIB_FILE)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX_LIB_FILE) $(MLX_FLAGS) $(MLX_INC) -o $(NAME)

$(BONUS): $(OBJ_BONUS) $(LIB) $(MLX_LIB_FILE)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(MLX_LIB_FILE) $(MLX_FLAGS) $(MLX_INC) -o $(BONUS)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(LIB):
	make -C $(LIBDIR)

$(MLX_LIB_FILE):
	-make -C $(MLX_DIR)

.PHONY: all clean fclean re

start:	all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx.supp ./bin/cube3d config/map.cub

startb: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx.supp ./bin/cube3d_bonus config/map_bonus.cub

it:
	./bin/cube3d config/map.cub

itb:
	./bin/cube3d_bonus config/map_bonus.cub



gdb : all
	gdb ./bin/cube3d

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -rf $(BIN_DIR)

re: fclean all

reb: fclean bonus
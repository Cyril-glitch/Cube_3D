NAME = raycasting

SOURCES = $(addprefix $(SRC_DIR)/, hooks.c raycasting.c main.c map_builder.c \
			pixel_management_1.c pixel_management_2.c trgb.c)

OBJECTS = $(SOURCES:src/%.c=obj/%.o)

SRC_DIR = src

CFLAGS = -Wall -Wextra -Werror -Wno-error=cast-function-type -Iminilibx-linux/include -Iincludes

LIBS = -Lminilibx-linux/lib -lmlx -lX11 -lXext -lm

all : libft $(NAME)

$(NAME) : libft/libft.a $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) libft/libft.a $(LIBS) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	cc $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C libft

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean libft

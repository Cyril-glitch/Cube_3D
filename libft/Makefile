NAME = lib/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc

SRC_LIBFT =  src/libft_src/ft_atoi.c \
       src/libft_src/ft_atol.c \
       src/libft_src/ft_isalnum.c \
       src/libft_src/ft_islower.c \
       src/libft_src/ft_itoa.c \
       src/libft_src/ft_memccpy.c \
       src/libft_src/ft_mempcpy.c \
       src/libft_src/ft_putnbr.c \
       src/libft_src/ft_strcat.c \
       src/libft_src/ft_striteri.c \
       src/libft_src/ft_strmapi.c \
       src/libft_src/ft_strrchr.c \
       src/libft_src/ft_toupper.c \
       src/libft_src/ft_bzero.c \
       src/libft_src/ft_isalpha.c \
       src/libft_src/ft_isprint.c \
       src/libft_src/ft_memchr.c \
       src/libft_src/ft_memrchr.c \
       src/libft_src/ft_putnbr_fd.c \
       src/libft_src/ft_strchr.c \
       src/libft_src/ft_strjoin.c \
       src/libft_src/ft_strncat.c \
       src/libft_src/ft_strstr.c \
       src/libft_src/ft_calloc.c \
       src/libft_src/ft_isascii.c \
       src/libft_src/ft_isset.c \
       src/libft_src/ft_memcmp.c \
       src/libft_src/ft_memset.c \
       src/libft_src/ft_putstr.c \
       src/libft_src/ft_strcmp.c \
       src/libft_src/ft_strlcat.c \
       src/libft_src/ft_strncmp.c \
       src/libft_src/ft_strtrim.c \
       src/libft_src/ft_countword.c \
       src/libft_src/ft_ischarset.c \
       src/libft_src/ft_isspace.c \
       src/libft_src/ft_memcpy.c \
       src/libft_src/ft_putchar_fd.c \
       src/libft_src/ft_putstr_fd.c \
       src/libft_src/ft_strcpy.c \
       src/libft_src/ft_strlcpy.c \
       src/libft_src/ft_strncpy.c \
       src/libft_src/ft_substr.c \
       src/libft_src/ft_freeiter.c \
       src/libft_src/ft_isdigit.c \
       src/libft_src/ft_isupper.c \
       src/libft_src/ft_memmove.c \
       src/libft_src/ft_putendl_fd.c \
       src/libft_src/ft_split.c \
       src/libft_src/ft_set_split.c \
       src/libft_src/ft_strdup.c \
       src/libft_src/ft_strlen.c \
       src/libft_src/ft_strnstr.c \
       src/libft_src/ft_tolower.c \
       src/libft_src/ft_dtablen.c \
       src/libft_src/ft_freedtab.c \
       src/libft_src/ft_freeall.c \
       src/libft_src/ft_tablen.c \
       src/libft_src/ft_atoll.c \
       src/libft_src/ft_sort_dtab.c \
       src/libft_src/ft_isfull_dig.c

SRC_PRINTF = src/ft_printf_src/ft_flags.utils.c \
       src/ft_printf_src/ft_printf.c \
       src/ft_printf_src/ft_printptr_hex.c \
       src/ft_printf_src/ft_printupper_hex.c \
       src/ft_printf_src/ft_fmtinit.c \
       src/ft_printf_src/ft_padandprint.c \
       src/ft_printf_src/ft_printlower_hex.c \
       src/ft_printf_src/ft_printstr.c \
       src/ft_printf_src/ft_utoabase.c \
       src/ft_printf_src/ft_format.utils.c \
       src/ft_printf_src/ft_printchar.c \
       src/ft_printf_src/ft_printnbr.c \
       src/ft_printf_src/ft_zero.c \
       src/ft_printf_src/ft_printunsigned.c \
       src/ft_printf_src/ft_putdouble.c \
       src/ft_printf_src/ft_dtoa.c

SRC = $(SRC_LIBFT) $(SRC_PRINTF)

OBJ = $(SRC:.c=.o)

SRCBO = src/libft_src/ft_lstadd_back.c \
        src/libft_src/ft_lstadd_front.c \
        src/libft_src/ft_lstclear.c \
        src/libft_src/ft_lstdelone.c \
        src/libft_src/ft_lstiter.c \
        src/libft_src/ft_lstlast.c \
        src/libft_src/ft_lstmap.c \
        src/libft_src/ft_lstnew.c \
        src/libft_src/ft_lstsize.c

OBJBO = $(SRCBO:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJBO)
	ar -rcs $(NAME) $(OBJ) $(OBJBO)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJBO) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

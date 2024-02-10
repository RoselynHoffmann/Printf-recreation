NAME = libftprintf.a
LIBFT_DIR = libft

SOURCES = ft_print_norm.c \
          ft_print_hex.c \
          ft_print_ptr.c \
          ft_print_unsigned.c \
          ft_printf.c \
          $(LIBFT_DIR)/ft_itoa.c \
          $(LIBFT_DIR)/ft_strdup.c \
		  $(LIBFT_DIR)/ft_strlcpy.c \
		  $(LIBFT_DIR)/ft_strlen.c \

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libft.a $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

libft.a:
	make -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

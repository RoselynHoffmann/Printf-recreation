NAME = libft.a
SOURCES = ft_strdup.c \
ft_itoa.c \
ft_strlcpy.c \
ft_strlen.c \

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
CFLAGS = -g -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
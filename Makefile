NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find . -name '*.c')

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


CC = CC
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJECTS	= $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

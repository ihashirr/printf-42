CC = CC
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a
EXE = ft_printf
SRCS = ft_printf.c ft_printf_utils.c

OBJECTS	= $(SRCS:.c=.o)

all: $(NAME) $(EXE)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $^
 
$(EXE) : $(NAME)
	$(CC) $(CFLAGS) $(NAME) ft_printf.c -o $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re
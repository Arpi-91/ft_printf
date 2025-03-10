NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c printf_utils.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

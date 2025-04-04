NAME := libftprintf.a

CC := cc

FLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c ft_printf_utils.c ft_printf_u.c ft_printf_x.c ft_printf_p.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

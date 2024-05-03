NAME	= push_swap
SRC_DIR = srcs/
SRCS	= main.c checker.c array.c stack.c ops_swap.c ops_push.c ops_rotate.c ops_rev_rotate.c
SRCS	:= $(addprefix $(SRC_DIR), $(SRCS))
OBJS	= $(SRCS:.c=.o)
LIB		= ./libft/libft.a
CC		= cc -Wall -Wextra -Werror -Iincludes

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iincludes -c $< -o $@ -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIB) -o $(NAME) -fsanitize=address

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus

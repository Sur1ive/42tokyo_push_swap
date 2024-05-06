NAME	= push_swap
SRC_DIR = srcs/sort/
SRCS	= main.c checker.c array.c stack.c stack2.c math.c push_swap.c push_swap5.c\
	ops_swap.c ops_push.c ops_rotate.c ops_rev_rotate.c ops_rotate_advanced.c
SRCS	:= $(addprefix $(SRC_DIR), $(SRCS))
OBJS	= $(SRCS:.c=.o)

NAMEB	= checker
SRCB_DIR = srcs/checker/
SRCSB	=
SRCSB	:= $(addprefix $(SRCB_DIR), $(SRCSB))
OBJSB	= $(SRCSB:.c=.o)

LIB		= ./libft/libft.a
CC		= cc -Wall -Wextra -Werror -Iincludes

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iincludes -c $< -o $@ -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
# $(CC) $(OBJS) $(LIB) -o $(NAME)
	$(CC) $(OBJS) $(LIB) -o $(NAME) -fsanitize=address

$(NAMEB): $(OBJSB)
	make -C libft
# $(CC) $(OBJSB) $(LIB) -o $(NAMEB)
	$(CC) $(OBJSB) $(LIB) -o $(NAMEB) -fsanitize=address

bonus: $(NAMEB)

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus

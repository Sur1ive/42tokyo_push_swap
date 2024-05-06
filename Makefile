NAME	= push_swap
SRC_DIR = srcs/sort/
SRCS	= checker.c array.c stack.c stack2.c stack3.c math.c push_swap.c push_swap5.c\
	ops_swap.c ops_push.c ops_rotate.c ops_rev_rotate.c ops_rotate_advanced.c
SRCS	:= $(addprefix $(SRC_DIR), $(SRCS))
SRCSM	= srcs/sort/main.c $(SRCS)
OBJSM	= $(SRCSM:.c=.o)

NAMEB	= checker
SRCSB = srcs/checker/main.c $(SRCS)
OBJSB	= $(SRCSB:.c=.o)

LIB		= ./libft/libft.a
CC		= cc -Wall -Wextra -Werror -Iincludes

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Iincludes -c $< -o $@ -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJSM)
	make -C libft
	$(CC) $(OBJSM) $(LIB) -o $(NAME)
# 	$(CC) $(OBJSM) $(LIB) -o $(NAME) -fsanitize=address

$(NAMEB): $(OBJSB)
	make -C libft
	$(CC) $(OBJSB) $(LIB) -o $(NAMEB)
# 	$(CC) $(OBJSB) $(LIB) -o $(NAMEB) -fsanitize=address

bonus: $(NAMEB)

clean:
	rm -rf $(OBJSM) $(OBJSB)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAMEB) $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus

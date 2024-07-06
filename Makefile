NAME = push_swap
SRCS = main.c rules.c utils.c free.c arg_check.c sort.c medium_sort.c set_stack.c ans_list_utils.c ans_list_utils2.c short_sort.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):$(OBJS)
		@$(MAKE) -s -C ./libft
		@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

all:$(NAME)

clean:
		@$(MAKE)  -s -C ./libft clean
		rm -f $(OBJS)

fclean:clean
		@$(MAKE) -s -C ./libft fclean
		rm -f $(NAME)

re: fclean all
NAME = push_swap
SRC_DIR = src/
INCLUDE_DIR = include/
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)

.PHONY: all clean fclean re

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
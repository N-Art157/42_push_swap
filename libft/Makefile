NAME = libft.a
SRCS = ft_putendl_fd.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_split.c ft_isdigit.c ft_atoi.c ft_strncmp.c ft_calloc.c ft_bzero.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):$(OBJS)
		ar rc $(NAME) $(OBJS)

all:$(NAME)

clean:
		rm -f $(OBJS)

fclean:clean
		rm -f $(NAME)

re:fclean all
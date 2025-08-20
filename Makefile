NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIB_DIR = libft
LIBFT = $(LIB_DIR)/libft.a

MANDATORY_SRC = push_swap.c ft_error_handler.c ft_node_handler.c ft_deque_handler.c \
				ft_utils.c ft_auxiliaries.c ft_swap.c ft_push.c 

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(LIBFT) $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJ) -L$(LIB_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(LIB_DIR)

clean:
	rm -f $(MANDATORY_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

PHONY: all clean fclean re
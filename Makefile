NAME		= push_swap

CC		  = gcc
CFLAGS	  = -Wall -Werror -Wextra -g
INCLUDES	= includes
OBJDIR	  = objs

LIB_DIR	 = libft
LIBFT	   = $(LIB_DIR)/libft.a

SRC		 = push_swap.c ft_error_handler.c ft_node_handler.c ft_deque_handler.c \
			 ft_utils.c ft_auxiliaries.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c

OBJS		 = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

INCLUDE_DIRS = -I$(INCLUDES) -I$(LIB_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $(OBJS) -L$(LIB_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re

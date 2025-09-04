NAME		= push_swap
BONUS		= checker

CC		  	= gcc
CFLAGS	  	= -Wall -Werror -Wextra -g
#  -fsanitize=address
INCLUDES	= includes
OBJDIR	  	= objs

LIB_DIR	 	= libft
LIBFT	   	= $(LIB_DIR)/libft.a

SRC		 	=	push_swap.c ft_error_handler.c ft_node_handler.c ft_deque_handler.c \
				ft_core.c  ft_moves.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
				ft_cost.c ft_utils.c ft_utils_cost.c ft_utils_ds.c ft_utils_ps.c

SRC_BONUS 	= 	checker_bonus.c ft_error_handler.c ft_node_handler.c ft_deque_handler.c \
				ft_core.c  ft_moves.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
				ft_cost.c ft_utils.c ft_utils_cost.c ft_utils_ds.c ft_utils_ps.c ft_checker_moves_bonus.c

OBJS_BONUS	= $(addprefix $(OBJDIR)/, $(SRC_BONUS:.c=.o))


OBJS		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

INCLUDE_DIRS = -I$(INCLUDES) -I$(LIB_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $(OBJS) -L$(LIB_DIR) -lft

$(BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $(OBJS_BONUS) -L$(LIB_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

bonus: $(BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

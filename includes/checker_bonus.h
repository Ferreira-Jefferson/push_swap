#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include "push_swap.h"

int		ft_is_valid_move(char *input);
int		ft_handler_moves(t_deque *list_a);
void	ft_make_move(char *move, t_deque *list_a, t_deque *list_b);
void	push(char *move, t_deque *list_a, t_deque *list_b);
void	swap(t_deque *list_a, t_deque *list_b);
void	reverse(t_deque *list_a, t_deque *list_b);
void	rotate(t_deque *list_a, t_deque *list_b);

#endif
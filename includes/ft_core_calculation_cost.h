#ifndef FT_CORE_CALCULATION_COST_H
# define FT_CORE_CALCULATION_COST_H

# include <limits.h>
# include "ft_deque_handler.h"
# include "push_swap.h"

size_t	ft_index_to_insert_in_b(t_deque *list_b, int value);
int		ft_calculate_cost_a(t_deque *list, int index);
int		ft_calculate_cost_b(t_deque *list_a, t_deque *list_b);
size_t	ft_index_to_insert_in_b_reverse(t_deque *list_b, int value);
void	ft_calculate_cost_b_reverse(t_deque *list_a, t_deque *list_b);
int	ft_calculate_cost_b_return(t_deque *list, int index);

#endif
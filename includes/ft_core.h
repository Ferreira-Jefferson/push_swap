/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:17 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/23 16:31:33 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include <limits.h>
# include "ft_deque_handler.h"
# include "push_swap.h"

int		ft_is_it_ordered_by_top(t_deque *list);
int		ft_is_it_ordered_by_bottom(t_deque *list);
size_t	ft_index_to_insert_in_b(t_deque *list_b, int value);
int		ft_calculate_cost_a(t_deque *list, int index);
int		ft_calculate_cost_b(t_deque *list_a, t_deque *list_b);
void	ft_sort_three(t_deque *list);
void	ft_sort_four(t_deque *list_a,t_deque *list_b);
void	ft_move_a(t_deque *list_a, int cost);
void	ft_move_b(t_deque *list_b, int cost);
void	ft_move_both(t_deque *list_a, int cost_a, t_deque *list_b, int cost_b);
size_t	ft_index_to_insert_in_b_reverse(t_deque *list_b, int value);
int		ft_calculate_cost_b_reverse(t_deque *list_a, t_deque *list_b);

#endif
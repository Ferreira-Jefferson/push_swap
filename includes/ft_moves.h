/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:17 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:46:58 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVES_H
# define FT_MOVES_H

# include "push_swap.h"

int		ft_is_it_ordered_by_top(t_deque *list);
int		ft_is_it_ordered_by_bottom(t_deque *list);
void	ft_move_a(t_deque *list_a, int cost);
void	ft_move_b(t_deque *list_b, int cost);
void	ft_move_both(t_deque *list_a, int cost_a, t_deque *list_b, int cost_b);

#endif
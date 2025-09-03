/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:47:15 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:47:16 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COST_H
# define FT_COST_H

# include "ft_deque_handler.h"
# include "push_swap.h"

int		ft_calculate_cost_a(t_deque *list, int index);
int		ft_calculate_cost_b(t_deque *list_a, t_deque *list_b);
void	ft_calculate_cost_a_when_b_origin(t_deque *list_a, t_deque *list_b);
int		ft_calculate_cost_b_origin(t_deque *list, int index);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cost.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:47:25 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:47:26 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_COST_H
# define FT_UTILS_COST_H

# include "push_swap.h"

int		ft_calculare_real_cost(int cost_a, int cost_b);
size_t	ft_get_lowest_cost_index(t_deque *deque);
size_t	ft_index_to_insert_in_a(t_deque *list_a, int value);
size_t	ft_index_to_insert_in_b(t_deque *list_b, int value);

#endif
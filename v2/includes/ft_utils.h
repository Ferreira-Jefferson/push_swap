/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/31 17:50:59 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_deque_handler.h"
# include "ft_auxiliaries.h"

int		equal_signs(int cost_a, int cost_b);
t_node	*ft_get_node_by_index(t_deque *deque, size_t index);
t_node	*ft_detache_node_by_index(t_deque *deque, size_t index);
void	ft_free_deque(t_deque *deque);

#endif
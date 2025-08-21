/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:22:36 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_deque_handler.h"

void	ft_print_list(t_deque *deque);
t_node	*ft_detache_node_by_index(t_deque *deque, size_t index);
void	ft_free_deque(t_deque *deque);
size_t	ft_get_index_by_cost(t_deque *deque, int cost);

#endif
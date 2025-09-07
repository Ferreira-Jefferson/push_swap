/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ds.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:47:33 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/07 07:52:09 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_DS_H
# define FT_UTILS_DS_H

# include "ft_deque_handler.h"

t_node	*ft_get_node_by_index(t_deque *deque, size_t index);
t_node	*ft_detache_node_by_index(t_deque *deque, size_t index);
size_t	ft_get_index_of_lowest_value(t_deque *deque);
void	ft_free_deque(t_deque *deque);

#endif
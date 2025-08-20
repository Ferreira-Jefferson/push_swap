/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 12:12:49 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_deque_handler.h"

void	ft_invert_list(t_deque *deque);
void	ft_print_list(t_deque *deque);
t_node	*ft_detache_node_by_index(t_deque *deque, size_t index);
void	ft_clear_deque(t_deque *deque);

#endif
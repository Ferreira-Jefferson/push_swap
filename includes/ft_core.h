/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:45:39 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:46:27 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include "ft_deque_handler.h"
# include "push_swap.h"

void	ft_sort_three(t_deque *list);
void	ft_sort_four(t_deque *list_a, t_deque *list_b);
void	ft_sort_any(t_deque *list_a, t_deque *list_b);
void	ft_final_rotate(t_deque *list_a);

#endif
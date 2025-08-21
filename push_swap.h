/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:07:23 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:08:03 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_error_handler.h"
# include "ft_deque_handler.h"
# include "ft_auxiliaries.h"
# include "ft_utils.h"

# include <stdlib.h>

void	sa(t_deque *stack_a, int is_ss);
void	sb(t_deque *stack_b, int is_ss);
void	ss(t_deque *stack_a, t_deque *stack_b);
void	ra(t_deque *list_a, int is_rr);
void	rb(t_deque *list_b, int is_rr);
void	rr(t_deque *list_a, t_deque *list_b);
void	rra(t_deque *list_a, int is_rrr);
void	rrb(t_deque *list_b, int is_rrr);
void	rrr(t_deque *list_a, t_deque *list_b);
void	pa(t_deque *list_a, t_deque *list_b);
void	pb(t_deque *list_a, t_deque *list_b);

#endif
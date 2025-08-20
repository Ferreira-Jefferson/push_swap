/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:07:23 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 15:38:02 by jtertuli         ###   ########.fr       */
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

void	sa(t_deque *stack_a);
void	sb(t_deque *stack_b);
void	ss(t_deque *stack_a, t_deque *stack_b);
void	pa(t_deque *list_a, t_deque *list_b);
void	pb(t_deque *list_a, t_deque *list_b);

#endif
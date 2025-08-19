/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:09:26 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/19 10:29:32 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_DEQUE_HANDLER_H
# define FT_DEQUE_HANDLER_H

# include "ft_node_handler.h"

typedef struct s_deque t_deque;

typedef struct s_deque {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_deque;

t_deque *ft_deque_create(void);
void	ft_deque_push_top(t_deque *deque, int value);
void	ft_deque_push_bottom(t_deque *deque, int value);
void	ft_deque_pop_top(t_deque *deque);
void	ft_deque_pop_bottom(t_deque *deque);

#endif
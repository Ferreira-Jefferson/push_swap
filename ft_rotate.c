/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:28:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 16:39:42 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_deque *list)
{
	t_node *node;
	node = ft_detache_node_by_index(list, 0);
	if (!node)
		return ;
	ft_deque_push_bottom(list, node->value);	
}

void	ra(t_deque *list_a)
{
	if (!list_a || list_a->size <= 1)
		return ;
	rotate(list_a);
	ft_printf("ra\n");
}

void	rb(t_deque *list_b)
{
	if (!list_b || list_b->size <= 1)
		return ;
	rotate(list_b);
	ft_printf("rb\n");
}

void	rr(t_deque *list_a, t_deque *list_b)
{
	ra(list_a);
	rb(list_b);
	ft_printf("rr\n");
}
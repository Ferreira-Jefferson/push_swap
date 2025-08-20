/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:28:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 16:41:50 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse(t_deque *list)
{
	t_node *node;
	node = ft_detache_node_by_index(list, list->size - 1);
	if (!node)
		return ;
	ft_deque_push_top(list, node->value);	
}

void	rra(t_deque *list_a)
{
	if (!list_a || list_a->size <= 1)
		return ;
	reverse(list_a);
	ft_printf("rra\n");
}

void	rrb(t_deque *list_b)
{
	if (!list_b || list_b->size <= 1)
		return ;
	reverse(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_deque *list_a, t_deque *list_b)
{
	rra(list_a);
	rrb(list_b);
	ft_printf("rr\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:28:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:06:59 by jtertuli         ###   ########.fr       */
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

void	rra(t_deque *list_a, int is_rrr)
{
	if (!list_a || list_a->size <= 1)
		return ;
	reverse(list_a);
	if (!is_rrr)
		ft_printf("rra\n");
}

void	rrb(t_deque *list_b, int is_rrr)
{
	if (!list_b || list_b->size <= 1)
		return ;
	reverse(list_b);
	if (!is_rrr)
		ft_printf("rrb\n");
}

void	rrr(t_deque *list_a, t_deque *list_b)
{
	rra(list_a, 1);
	rrb(list_b, 1);
	ft_printf("rr\n");
}
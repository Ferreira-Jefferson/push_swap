/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_moves_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:49:57 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/04 14:45:46 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker_bonus.h"
#include "includes/push_swap.h"

void	push(char *move, t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	if (ft_strncmp(move, "pa", 2) == 0)
	{
		node = ft_detache_node_by_index(list_b, 0);
		if (!node)
			return ;
		ft_deque_push_top(list_a, node->value);
	}
	else
	{
		node = ft_detache_node_by_index(list_a, 0);
		if (!node)
			return ;
		ft_deque_push_top(list_b, node->value);
	}
}

void	swap(t_deque *list_a, t_deque *list_b)
{
	t_node	*node_1;
	t_node	*node_2;
	int		temp;

	if (list_a)
	{
		node_1 = list_a->top;
		node_2 = list_a->top->next;
		temp = node_1->value;
		node_1->value = node_2->value;
		node_2->value = temp;
	}
	if (list_b)
	{
		node_1 = list_b->top;
		node_2 = list_b->top->next;
		temp = node_1->value;
		node_1->value = node_2->value;
		node_2->value = temp;
	}
}

void	reverse(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	if (list_a)
	{
		node = ft_detache_node_by_index(list_a, list_a->size - 1);
		if (!node)
			return ;
		ft_deque_push_top(list_a, node->value);
	}
	if (list_b)
	{
		node = ft_detache_node_by_index(list_b, list_b->size - 1);
		if (!node)
			return ;
		ft_deque_push_top(list_b, node->value);
	}
}

void	rotate(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	if (list_a)
	{
		node = ft_detache_node_by_index(list_a, 0);
		if (!node)
			return ;
		ft_deque_push_bottom(list_a, node->value);
	}
	if (list_b)
	{
		node = ft_detache_node_by_index(list_b, 0);
		if (!node)
			return ;
		ft_deque_push_bottom(list_b, node->value);
	}
}

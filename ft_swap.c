/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:16:15 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 15:23:51 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_deque *list)
{
	t_node	*node_1;
	t_node	*node_2;
	int		temp;

	node_1 = list->top;
	node_2 = list->top->next;
	temp = node_1->value;
	node_1->value = node_2->value;
	node_2->value = temp;
}

void sa(t_deque *list_a)
{
	if (!list_a || list_a->size <= 1)
		return ;
	swap(list_a);
	ft_printf("sa\n");
}

void sb(t_deque *list_b)
{
	if (!list_b || list_b->size <= 1)
		return ;
	swap(list_b);
	ft_printf("sb\n");
}

void ss(t_deque *list_a, t_deque *list_b)
{
	sa(list_a);
	sb(list_b);
	ft_printf("ss\n");
}
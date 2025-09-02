/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:16:15 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/22 16:44:52 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	swap(t_deque *list)
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

void	sa(t_deque *list_a, int is_ss)
{
	if (!list_a || list_a->size <= 1)
		return ;
	swap(list_a);
	if (!is_ss)
		ft_printf("sa\n");
}

void	sb(t_deque *list_b, int is_ss)
{
	if (!list_b || list_b->size <= 1)
		return ;
	swap(list_b);
	if (!is_ss)
		ft_printf("sb\n");
}

void	ss(t_deque *list_a, t_deque *list_b)
{
	sa(list_a, 1);
	sb(list_b, 1);
	ft_printf("ss\n");
}

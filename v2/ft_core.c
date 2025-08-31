/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:59 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/24 13:34:21 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_core.h"

int	ft_is_it_ordered_by_top(t_deque *list)
{
	int		prev;
	t_node	*head;

	if (!list || list->size <= 1)
		return (1);
	head = list->top;
	prev = head->value;
	head = head->next;
	while (head)
	{
		if (prev > head->value)
			return (0);
		prev = head->value;
		head = head->next;
	}
	return (1);
}

int	ft_is_it_ordered_by_bottom(t_deque *list)
{
	int		prev;
	t_node	*head;

	if (!list || list->size <= 1)
		return (1);
	head = list->bottom;
	prev = head->value;
	head = head->prev;
	while (head)
	{	
		if (prev > head->value)
			return (0);
		prev = head->value;
		head = head->prev;
	}
	return (1);
}

void	ft_move_a(t_deque *list_a, int cost)
{
	if (cost < 0)
	{
		while (cost)
		{
			rra(list_a, 0);
			cost++;
		}		
	}
	while (cost)
	{
		ra(list_a, 0);
		cost--;
	}	
}

void	ft_move_b(t_deque *list_b, int cost)
{
	if (cost < 0)
	{
		while (cost)
		{
			rrb(list_b, 0);
			cost++;
		}		
	}
	while (cost)
	{
		rb(list_b, 0);
		cost--;
	}	
}

void	ft_move_both(t_deque *list_a, int cost_a, t_deque *list_b, int cost_b)
{
	int abs_cost_a;
	int abs_cost_b;

	abs_cost_a = ft_abs(cost_a);
	abs_cost_b = ft_abs(cost_b);
	while (abs_cost_a && abs_cost_b)
	{
		if (cost_a < 0)
			rrr(list_a, list_b);
		else
			rr(list_a, list_b);
		abs_cost_a--;
		abs_cost_b--;
	}
	while (abs_cost_a > 0 || abs_cost_b > 0)
	{
		if (abs_cost_a)
			ft_move_a(list_a, cost_a);
		else if (abs_cost_b)
			ft_move_b(list_b, cost_b);
		abs_cost_a--;
		abs_cost_b--;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:45:10 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_utils_cost.h"

int	ft_calculare_real_cost(int cost_a, int cost_b)
{
	if (ft_equal_signs(cost_a, cost_b))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

size_t	ft_get_lowest_cost_index(t_deque *deque)
{
	size_t	index;
	size_t	index_lowest;
	t_node	*head;
	int		lowest;

	if (!deque || deque->size == 0)
		return (deque->size);
	head = deque->top;
	lowest = ft_calculare_real_cost(head->cost_a, head->cost_b);
	index = 0;
	index_lowest = 0;
	while (head)
	{
		if (ft_calculare_real_cost(head->cost_a, head->cost_b) < lowest)
		{
			index_lowest = index;
			lowest = ft_calculare_real_cost(head->cost_a, head->cost_b);
		}
		index++;
		head = head->next;
	}
	return (index_lowest);
}

size_t	ft_index_to_insert_in_a(t_deque *list_a, int value)
{
	t_node	*current;
	size_t	index;
	int		min;
	int		max;

	if (!list_a || list_a->size == 0)
		return (0);
	ft_set_min_and_max(list_a, &min, &max);
	current = list_a->top;
	index = 0;
	while (current)
	{
		if ((value < min || value > max) && current->value == min)
			return (index);
		if (current->value <= value
			&& (current->next && value < current->next->value))
			return (index + 1);
		current = current->next;
		index++;
	}
	return (0);
}

size_t	ft_index_to_insert_in_b(t_deque *list_b, int value)
{
	t_node	*current;
	size_t	index;
	int		min;
	int		max;

	current = list_b->top;
	ft_set_min_and_max(list_b, &min, &max);
	index = 0;
	while (current)
	{
		if ((value > max || value < min) && current->value == max)
			return (index);
		else if (current->value >= value
			&& (current->next && value > current->next->value))
			return (index + 1);
		current = current->next;
		index++;
	}
	return (0);
}

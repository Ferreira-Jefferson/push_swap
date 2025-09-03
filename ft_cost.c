/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:40:16 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:41:24 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_cost.h"

int	ft_calculate_cost_a(t_deque *list, int index)
{
	t_node	*head;
	size_t	current_index;

	if (index >= 0)
	{
		if (index <= (int) list->size / 2)
			return (index);
		else
			return (-(list->size - index));
	}
	current_index = 0;
	head = list->top;
	while (head)
	{
		head->cost_a = ft_calculate_cost_a(list, current_index);
		head = head->next;
		current_index++;
	}
	return (0);
}

int	ft_calculate_cost_b(t_deque *list_a, t_deque *list_b)
{
	t_node	*head;
	int		index;

	head = list_a->top;
	while (head)
	{
		index = ft_index_to_insert_in_b(list_b, head->value);
		if (index <= (int) list_b->size / 2)
			head->cost_b = index;
		else
			head->cost_b = -(list_b->size - index);
		head = head->next;
	}
	return (0);
}

int	ft_calculate_cost_b_origin(t_deque *list, int index)
{
	t_node	*head;
	size_t	current_index;

	if (index >= 0)
	{
		if (index <= (int) list->size / 2)
			return (index);
		else
			return (-(list->size - index));
	}
	current_index = 0;
	head = list->top;
	while (head)
	{
		head->cost_b = ft_calculate_cost_b_origin(list, current_index);
		head = head->next;
		current_index++;
	}
	return (0);
}

void	ft_calculate_cost_a_when_b_origin(t_deque *list_a, t_deque *list_b)
{
	t_node	*current;
	int		index;

	if (!list_a || !list_b || list_b->size == 0)
		return ;
	current = list_b->top;
	while (current)
	{
		index = ft_index_to_insert_in_a(list_a, current->value);
		if (index <= (int) list_a->size / 2)
			current->cost_a = index;
		else
			current->cost_a = -(list_a->size - index);
		current = current->next;
	}
}

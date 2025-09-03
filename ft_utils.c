/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:37:28 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_utils.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	ft_equal_signs(int cost_a, int cost_b)
{
	if (cost_a == 0 && cost_b == 0)
		return (1);
	if (cost_a > 0 && cost_b > 0)
		return (1);
	if (cost_a < 0 && cost_b < 0)
		return (1);
	return (0);
}

int	ft_get_min(t_deque *list_a)
{
	int		min;
	int		index;
	int		index_min;
	t_node	*head;

	head = list_a->top;
	min = head->value;
	index = 0;
	index_min = 0;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			index_min = index;
		}
		head = head->next;
		index++;
	}
	return (index_min);
}

void	ft_set_min_and_max(t_deque *list, int *min, int *max)
{
	t_node	*head;

	*min = list->top->value;
	*max = list->top->value;
	head = list->top;
	while (head)
	{
		if (head->value > *max)
			*max = head->value;
		if (head->value < *min)
			*min = head->value;
		head = head->next;
	}
}

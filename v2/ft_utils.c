/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/31 17:50:40 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_utils.h"

int equal_signs(int cost_a, int cost_b)
{
	if (cost_a == 0 && cost_b == 0)
		return (1);
	if (cost_a > 0 && cost_b > 0)
		return (1);
	if (cost_a < 0 && cost_b < 0)
		return (1);
	return (0);
}

t_node	*ft_get_node_by_index(t_deque *deque, size_t index)
{
	t_node	*node;
	size_t	i;

	if (index < deque->size / 2)
	{
		i = 0;
		node = deque->top;
		while (node)
		{
			if (i == index)
				return (node);
			node = node->next;
			i++;
		}
	}
	i = deque->size - 1;
	node = deque->bottom;
	while (i >= deque->size / 2)
	{
		if (i == index)
			return (node);
		node = node->prev;
		i--;
	}
	return (NULL);
}

t_node	*ft_detache_node_by_index(t_deque *deque, size_t index)
{
	t_node	*node;

	if (!deque || deque->size == 0 || index >= deque->size)
		return (NULL);
	node = ft_get_node_by_index(deque, index);
	if (!node)
		return (NULL);
	if (node->prev)
		node->prev->next = node->next;
	else
		deque->top = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		deque->bottom = node->prev;
	deque->size--;
	return (node);
}

void	ft_free_deque(t_deque *deque)
{
	t_node	*head;
	t_node	*to_free;

	if (!deque || deque->size == 0)
		return ;
	head = deque->top;
	while (head)
	{
		to_free = head;
		head = head->next;
		ft_to_free((void **) &to_free);
	}
	ft_to_free((void **) &deque);
}

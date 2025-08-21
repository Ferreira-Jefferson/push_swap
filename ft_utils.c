/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:31:31 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_handler.h"

static t_node	*ft_get_node(t_deque *deque, size_t index)
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
	node = ft_get_node(deque, index);
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

size_t	ft_get_index_by_cost(t_deque *deque, int cost)
{
	size_t	index;
	t_node	*head;

	if (!deque || deque->size == 0)
		return (deque->size);
	head = deque->top;
	index = 0;
	while (head && head->cost != cost)
	{
		head = head->next;
		index++;
	}
	return (index);
}

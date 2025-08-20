/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 12:55:34 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_handler.h"

void	ft_invert_list(t_deque *deque)
{
	t_node	*temp;
	t_node	*current;
	t_node	*next;

	if (deque->size == 0)
		return ;
	current = deque->top;
	next = deque->top->next;
	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = next;
		if (next)
			next = next->next;
	}
	temp = deque->top;
	deque->top = deque->bottom;
	deque->bottom = temp;
}

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

void	ft_clear_deque(t_deque *deque)
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
	deque->top = NULL;
	deque->bottom = NULL;
	deque->size = 0;
}

size_t	ft_get_index(t_deque *deque, int value)
{
	size_t	index;
	t_node	*head;

	if (!deque || deque->size == 0)
		return (deque->size);
	head = deque->top;
	index = 0;
	while (head && head->value != value)
	{
		head = head->next;
		index++;
	}
	return (index);
}
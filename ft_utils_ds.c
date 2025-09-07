/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:00:08 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/07 09:09:31 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_utils_ds.h"

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

size_t	ft_get_index_of_lowest_value(t_deque *deque)
{
	size_t	index;
	size_t	index_lowest;
	t_node	*head;
	int		lowest;

	if (!deque || deque->size == 0)
		return (deque->size);
	head = deque->top;
	lowest = head->value;
	index = 0;
	index_lowest = 0;
	while (head)
	{
		if (head->value < lowest)
		{
			index_lowest = index;
			lowest = head->value;
		}
		index++;
		head = head->next;
	}
	return (index_lowest);
}

void    ft_free_deque(t_deque *deque)
{
    t_node  *head;
    t_node  *to_free;

    if (!deque || !deque)
        return ;
    head = deque->top;
    while (head)
    {
        to_free = head;
        head = head->next;
        ft_to_free((void **) &to_free);
    }
    ft_to_free((void **) &deque);;
}

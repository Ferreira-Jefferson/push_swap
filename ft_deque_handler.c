/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:11:21 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:47:36 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_deque_handler.h"

t_deque	*ft_deque_create(void)
{
	t_deque	*new_deque;

	new_deque = (t_deque *) malloc(sizeof(t_deque));
	if (!new_deque)
		return (NULL);
	new_deque->top = NULL;
	new_deque->bottom = NULL;
	new_deque->size = 0;
	return (new_deque);
}

void	ft_deque_push_top(t_deque *deque, int value)
{
	t_node	*new_node;

	if (!deque)
		return ;
	new_node = ft_node_create(value);
	if (!new_node)
		return ;
	if (deque->size == 0)
	{
		deque->top = new_node;
		deque->bottom = new_node;
		deque->size = 1;
		return ;
	}
	new_node->next = deque->top;
	deque->top->prev = new_node;
	deque->top = new_node;
	deque->size++;
}

void	ft_deque_push_bottom(t_deque *deque, int value)
{
	t_node	*new_node;

	if (!deque)
		return ;
	new_node = ft_node_create(value);
	if (!new_node)
		return ;
	if (deque->size == 0)
	{
		deque->top = new_node;
		deque->bottom = new_node;
		deque->size = 1;
		return ;
	}
	new_node->prev = deque->bottom;
	deque->bottom->next = new_node;
	deque->bottom = new_node;
	deque->size++;
}

void	ft_deque_pop_top(t_deque *deque)
{
	t_node	*to_free;

	if (!deque)
		return ;
	if (!deque->top)
		return ;
	if (deque->size == 1)
	{
		deque->top = ft_to_free((void **) &deque->top);
		deque->bottom = NULL;
		deque->size = 0;
		return ;
	}
	to_free = deque->top;
	deque->top = deque->top->next;
	deque->top->prev = NULL;
	deque->size--;
	ft_to_free((void **) &to_free);
}

void	ft_deque_pop_bottom(t_deque *deque)
{
	t_node	*to_free;

	if (!deque)
		return ;
	if (!deque->bottom)
		return ;
	if (deque->size == 1)
	{
		deque->bottom = ft_to_free((void **) &deque->bottom);
		deque->top = NULL;
		deque->size = 0;
		return ;
	}
	to_free = deque->bottom;
	deque->bottom = deque->bottom->prev;
	deque->bottom->next = NULL;
	deque->size--;
	ft_to_free((void **) &to_free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:11:21 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/18 10:06:31 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

// create deque
t_deque *ft_deque_create(void)
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

// insert node in top deque
void ft_deque_push_front(t_deque *deque, int value)
{

}

// insert node in bottom deque
void ft_deque_push_bottom(t_deque *deque, int value)
{

}

// remove node top in deque

// remove node botton in deque


// invert deque

// size deque = ft_lstsize

// clear deque = ft_lstclear

// print deque


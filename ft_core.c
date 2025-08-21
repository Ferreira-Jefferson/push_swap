/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:59 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 17:39:56 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_core.h"

// verifica se a lista está ordenado

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

void	ft_sort_three(t_deque *list)
{
	int	top;
	int	middle;
	int	bottom;

	if (ft_is_it_ordered_by_top(list))
		return ;
	if (ft_is_it_ordered_by_bottom(list))
	{
		ra(list, 0);
		sa(list, 0);
		return ;
	}
	middle = list->top->next->value;
	top = list->top->value;
	bottom = list->bottom->value;
	if (top > middle && top < bottom)
		return (sa(list, 0));
	if (top > middle && top > bottom)
		return (ra(list, 0));
	rra(list, 0);
}

// calcular o custos
	// calcular o custo de A
	// calcular o custo de B
// decidir qual mover
	// executar movimento
	// resetar os custo
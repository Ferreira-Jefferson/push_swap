/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:59 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/24 13:34:21 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_core.h"

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

static void	ft_set_min_and_max(t_deque *list_b, int *min, int *max)
{
	t_node	*head;

	*min = INT_MAX;
	*max = INT_MIN;
	head = list_b->top;
	while (head)
	{
		if (head->value > *max)
			*max = head->value;
		if (head->value < *min)
			*min = head->value;
		head = head->next;
	}
}

size_t	ft_index_to_insert_in_b_reverse(t_deque *list_a, int value)
{
	t_node	*current;
	size_t	index;
	int	index_candidate;
	int		min;
	int		max;

	current = list_a->top;
	ft_set_min_and_max(list_a, &min, &max);
	index = 0;
	index_candidate = -1;
	while (current)
	{
		if (current->value < value && current->value > min)
		{
			min = current->value;
			index_candidate = index + 1;
		}
		else if (current->value > value && current->value < max)
		{
			max = current->value;
			index_candidate = index;
		}
		current = current->next;
		index++;
	}
	return (index_candidate);
}

void	ft_calculate_cost_b_reverse(t_deque *list_a, t_deque *list_b)
{
	int		index;
	if (!list_a || !list_b)
		return ;
	if (!list_a->size || !list_b->size)
		return ;
	index = ft_index_to_insert_in_b_reverse(list_a, list_b->top->value);
	ft_printf("\nvalue: %d | index_candidate fora: %d | ocst_a: %d\n", list_b->top->value, index, list_b->top->cost_a);
	if (index <= (int) list_a->size / 2)
	{
		list_b->top->cost_a = (index);
		ft_printf("value: %d | index_candidate#: %d", list_b->top->value, list_b->top->cost_a);
	}
	else
	{
		list_b->top->cost_a = -(list_a->size - index);
		ft_printf("index_candidate: %d", list_b->top->cost_a);
	}
}


size_t	ft_index_to_insert_in_b(t_deque *list_b, int value)
{
	t_node	*current;
	size_t	index;
	size_t	index_to_return;
	int		min;
	int		max;

	current = list_b->top;
	ft_set_min_and_max(list_b, &min, &max);
	index_to_return = 0;
	index = 0;
	while (current)
	{
		if ((value > max || value < min) && current->value == max)
			return (index);
		else if (current->value >= value && (current->next && value > current->next->value))
			return (index + 1);
		current = current->next;
		index++;
	}
	return (index_to_return);
}

int	ft_calculate_cost_a(t_deque *list, int index)
{
	t_node	*head;
	size_t	current_index;

	if (index >= 0)
	{
		if (index <= (int) list->size / 2)
			return (index);
		else
			return (-(list->size  - index));
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

void	ft_move_a(t_deque *list_a, int cost)
{
	if (cost < 0)
	{
		while (cost)
		{
			rra(list_a, 0);
			cost++;
		}		
	}
	while (cost)
	{
		ra(list_a, 0);
		cost--;
	}	
}

void	ft_move_b(t_deque *list_b, int cost)
{
	if (cost < 0)
	{
		while (cost)
		{
			rrb(list_b, 0);
			cost++;
		}		
	}
	while (cost)
	{
		rb(list_b, 0);
		cost--;
	}	
}

void	ft_move_both(t_deque *list_a, int cost_a, t_deque *list_b, int cost_b)
{
	int abs_cost_a;
	int abs_cost_b;

	abs_cost_a = ft_abs(cost_a);
	abs_cost_b = ft_abs(cost_b);
	while (abs_cost_a && abs_cost_b)
	{
		if (cost_a < 0)
			rrr(list_a, list_b);
		else
			rr(list_a, list_b);
		abs_cost_a--;
		abs_cost_b--;
	}
	while (abs_cost_a > 0 || abs_cost_b > 0)
	{
		if (abs_cost_a)
			ft_move_a(list_a, cost_a);
		else if (abs_cost_b)
			ft_move_b(list_b, cost_b);
		abs_cost_a--;
		abs_cost_b--;
	}
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
	ra(list, 0);
	ft_sort_three(list);
}

void	ft_sort_four(t_deque *list_a,t_deque *list_b)
{
	int	index_lowest;
	int		cost;

	index_lowest = ft_get_index_of_lowest_value(list_a);
	cost = ft_calculate_cost_a(list_a, index_lowest);
	ft_move_a(list_a, cost);
	pb(list_a, list_b);
	ft_sort_three(list_a);
	pa(list_a, list_b);	
}

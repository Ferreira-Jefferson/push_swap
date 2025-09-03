/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:36:24 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:40:07 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "includes/ft_core.h"

static void	make_move(
	t_deque *list_a, t_deque *list_b, t_node *node_lowest_cost)
{
	if (ft_equal_signs(node_lowest_cost->cost_a, node_lowest_cost->cost_b))
		ft_move_both(
			list_a, node_lowest_cost->cost_a, list_b, node_lowest_cost->cost_b);
	else
	{
		ft_move_a(list_a, node_lowest_cost->cost_a);
		ft_move_b(list_b, node_lowest_cost->cost_b);
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

void	ft_sort_four(t_deque *list_a, t_deque *list_b)
{
	int	index_lowest;
	int	cost;

	index_lowest = ft_get_index_of_lowest_value(list_a);
	cost = ft_calculate_cost_a(list_a, index_lowest);
	ft_move_a(list_a, cost);
	pb(list_a, list_b);
	ft_sort_three(list_a);
	pa(list_a, list_b);
}

void	ft_sort_any(t_deque *list_a, t_deque *list_b)
{
	size_t	index_lowest_cost;

	pb(list_a, list_b);
	pb(list_a, list_b);
	if (list_b->top->value < list_b->bottom->value)
		sb(list_b, 0);
	while (list_a->size > 3)
	{
		ft_calculate_cost_a(list_a, -1);
		ft_calculate_cost_b(list_a, list_b);
		index_lowest_cost = ft_get_lowest_cost_index(list_a);
		make_move(list_a, list_b,
			ft_get_node_by_index(list_a, index_lowest_cost));
		pb(list_a, list_b);
	}
	ft_sort_three(list_a);
	while (list_b->size)
	{
		ft_calculate_cost_b_origin(list_b, -1);
		ft_calculate_cost_a_when_b_origin(list_a, list_b);
		index_lowest_cost = ft_get_lowest_cost_index(list_b);
		make_move(list_a, list_b,
			ft_get_node_by_index(list_b, index_lowest_cost));
		pa(list_a, list_b);
	}
}

void	ft_final_rotate(t_deque *list_a)
{
	int		index_min;

	while (!ft_is_it_ordered_by_top(list_a))
	{
		index_min = ft_get_min(list_a);
		if (index_min <= (int) list_a->size / 2)
			while (index_min--)
				ra(list_a, 0);
		else
		{
			index_min = list_a->size - index_min;
			while (index_min--)
				rra(list_a, 0);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:10:19 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/24 13:31:04 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void populate_list_with_args(t_deque *list, int argc, char *argv[])
{
	char	**values;
	int		i;

	values = ft_get_values( argc, argv);
	if (!values)
	{
		list = NULL;
		return ;
	}
	i = 0;
	while (values[i])
	{
		ft_deque_push_bottom(list, ft_atoi(values[i]));
		i++;
	}
	ft_free_str_vector(values);
}

static void	final_rotate_to_min(t_deque *list_a)
{
	int index_lowest = ft_get_index_of_lowest_value(list_a);
	int cost = ft_calculate_cost_a(list_a, index_lowest);
	ft_move_a(list_a, cost);
}

static void sort_list(t_deque *list_a)
{
	t_deque	*list_b;
	size_t	index_lowest_cost;
	t_node	*node_lowest_cost;

	if (ft_is_it_ordered_by_top(list_a))
		return ;
	if (list_a->size == 2)
	{
		if (list_a->top->value > list_a->bottom->value)
			sa(list_a, 0);
		return ;
	}
	if (list_a->size == 3)
		return(ft_sort_three(list_a));
	list_b = ft_deque_create();
	if (!list_b)
		return ;
	if (list_a->size == 4)
		return (ft_sort_four(list_a, list_b));
	pb(list_a, list_b);
	pb(list_a, list_b);
	if (list_b->top->value < list_b->bottom->value)
		sb(list_b, 0);
	while (list_a->size)
	{
		// Eu não estou contando o custo de girar os dois juntos, caso leve mais giros, isso pode ser observado.
		ft_reset_cost(list_a);
		ft_calculate_cost_a(list_a, -1);
		ft_calculate_cost_b(list_a, list_b);
		index_lowest_cost = ft_get_lowest_cost_index(list_a);
		node_lowest_cost = ft_get_node_by_index(list_a, index_lowest_cost);
		if (node_lowest_cost->cost_a > 0 && node_lowest_cost->cost_b > 0)
			ft_move_both(list_a, node_lowest_cost->cost_a, list_b, node_lowest_cost->cost_b);
		else if (node_lowest_cost->cost_a < 0 && node_lowest_cost->cost_b < 0)
			ft_move_both(list_a, node_lowest_cost->cost_a, list_b, node_lowest_cost->cost_b);
		else
		{
			ft_move_a(list_a, node_lowest_cost->cost_a);
			ft_move_b(list_b, node_lowest_cost->cost_b);
		}
		pb(list_a, list_b);
		if (list_a->size == 3)
			break;
	}
	ft_sort_three(list_a);
	ft_reset_cost(list_a);

	while (list_b->size)
	{
		ft_reset_cost(list_b);
		ft_calculate_cost_b_reverse(list_a, list_b);
		ft_move_a(list_a, list_b->top->cost_a);
		pa(list_a, list_b);
	}
	final_rotate_to_min(list_a);
}

int	main(int argc, char *argv[])
{
	t_deque	*list_a;

	if (ft_handle_input_error(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	list_a = ft_deque_create();
	if (!list_a)
		return (1);
	populate_list_with_args(list_a, argc, argv);
	sort_list(list_a);
	ft_free_deque(list_a);
	return (0);
}

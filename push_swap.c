/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:10:19 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/02 14:42:33 by jtertuli         ###   ########.fr       */
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
		ft_deque_push_bottom(list, ft_atol(values[i]));
		i++;
	}
	ft_free_str_vector(values);
}

static int ft_get_min(t_deque *list_a)
{
	int min;
	int index;
	int index_min;
	t_node *head;
	
	head = list_a->top;
	min = head->value;
	index = 0;
	index_min = 0;
	while (head)
	{
		if (head->value > min)
		{
			min = head->value;
			index_min = index;
		}
		head = head->next;
		index++;
	}
	return (index_min);
}
void	ft_final_rotate(t_deque *list_a)
{
	int		index_min;

	index_min = ft_get_min(list_a);
	if (index_min <= (int) list_a->size / 2)
		while (--index_min)
			ra(list_a, 0);
	else
	{
		index_min = list_a->size - index_min;
		while (--index_min)
			rra(list_a, 0);
	}
}



static void make_move(t_deque *list_a, t_deque *list_b, t_node *node_lowest_cost)
{
	if (equal_signs(node_lowest_cost->cost_a, node_lowest_cost->cost_b))
		ft_move_both(list_a, node_lowest_cost->cost_a, list_b, node_lowest_cost->cost_b);
	else
	{
		ft_move_a(list_a, node_lowest_cost->cost_a);
		ft_move_b(list_b, node_lowest_cost->cost_b);
	}
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
	while (list_a->size > 3)
	{
		ft_reset_cost(list_a);
		ft_calculate_cost_a(list_a, -1);
		ft_calculate_cost_b(list_a, list_b);
		index_lowest_cost = ft_get_lowest_cost_index(list_a);
		node_lowest_cost = ft_get_node_by_index(list_a, index_lowest_cost);
		// ft_printf("list_a\n");
		// ft_print_list(list_a);
		make_move(list_a, list_b, node_lowest_cost);
		pb(list_a, list_b);
		// ft_printf("list_b\n");
		// ft_print_list(list_b);
	}
	ft_sort_three(list_a);
	ft_reset_cost(list_a);
	// ft_printf("list_a sort three\n");
	// 	ft_print_list(list_a);
	while (list_b->size)
	{
		ft_reset_cost(list_b);
		ft_calculate_cost_b_return(list_b, -1);
		ft_calculate_cost_b_reverse(list_a, list_b);
		index_lowest_cost = ft_get_lowest_cost_index(list_b);
		node_lowest_cost = ft_get_node_by_index(list_b, index_lowest_cost);
		// ft_printf("list_b\n");
		// ft_print_list(list_b);

		make_move(list_a, list_b, node_lowest_cost);
		pa(list_a, list_b);

		// ft_printf("list_a\n");
		// ft_print_list(list_a);
	}
	ft_final_rotate(list_a);
}

int	main(int argc, char *argv[])
{
	t_deque	*list_a;

	if (ft_handle_input_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	list_a = ft_deque_create();
	if (!list_a)
		return (1);
	populate_list_with_args(list_a, argc, argv);
	sort_list(list_a);
	// ft_printf("list_a final\n");
	//  ft_print_list(list_a);
	ft_free_deque(list_a);
	return (0);
}

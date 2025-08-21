/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:10:19 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:08:23 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void sort_list(t_deque *list_a)
{
	t_deque	*list_b;

	list_b = ft_deque_create();
	if (!list_b)
		return ;
	ss(list_a, list_b);
	ft_printf("\nlist_a\n");
	ft_print_list(list_a);

	pb(list_a, list_b);
	pb(list_a, list_b);
	ft_printf("\nlist_a\n");
	ft_print_list(list_a);
	ft_printf("\nlist_b\n");
	ft_print_list(list_b);

	ra(list_a, 0);
	rb(list_b, 0);
	ft_printf("\nlist_a\n");
	ft_print_list(list_a);
	ft_printf("\nlist_b\n");
	ft_print_list(list_b);

	rrr(list_a, list_b);
	ft_printf("\nlist_a\n");
	ft_print_list(list_a);
	ft_printf("\nlist_b\n");
	ft_print_list(list_b);
	// tem que ter uma calculate_cost
	
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
	ft_print_list(list_a);
	sort_list(list_a);
	ft_free_deque(list_a);
	return (0);
}

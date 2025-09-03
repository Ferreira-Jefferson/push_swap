/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:10:19 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 11:21:08 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	populate_list_with_args(t_deque *list, int argc, char *argv[])
{
	char	**values;
	int		i;

	values = ft_get_values(argc, argv);
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

static void	sort_list(t_deque *list_a)
{
	t_deque	*list_b;

	if (ft_is_it_ordered_by_top(list_a))
		return ;
	if (list_a->size == 2)
	{
		if (list_a->top->value > list_a->bottom->value)
			sa(list_a, 0);
		return ;
	}
	if (list_a->size == 3)
		return (ft_sort_three(list_a));
	list_b = ft_deque_create();
	if (!list_b)
		return ;
	if (list_a->size == 4)
		return (ft_sort_four(list_a, list_b));
	ft_sort_any(list_a, list_b);
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
	ft_free_deque(list_a);
	return (0);
}

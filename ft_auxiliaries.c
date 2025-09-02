/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:36:51 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/23 14:36:31 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_deque_handler.h"
#include "includes/ft_auxiliaries.h"

char	**ft_get_values(int argc, char *argv[])
{
	char	**values;
	char	*arg_values;

	if (argc == 2)
		arg_values = ft_strdup(argv[1]);
	else
		arg_values = ft_join_args(argc, argv);
	if (!arg_values)
		return (NULL);
	values = ft_split(arg_values, ' ');
	ft_to_free((void **)&arg_values);
	return (values);
}

char	*ft_join_args(int argc, char *argv[])
{
	int		i;
	char	*values;
	char	*values_args;
	char	*to_free;

	values = ft_strdup("");
	if (!values)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		values_args = ft_strjoin(argv[i], " ");
		if (!values_args)
			return (ft_to_free((void **) &values));
		to_free = values;
		values = ft_strjoin(values, values_args);
		ft_to_free((void **) &values_args);
		if (!values)
			return (ft_to_free((void **) &to_free));
		ft_to_free((void **) &to_free);
		i++;
	}
	return (values);
}

void	ft_print_list(t_deque *deque)
{
	size_t	i;
	t_node	*head;

	head = deque->top;
	i = 0;
	while (i < deque->size)
	{
		//  ft_printf("[%d]: %d\n", i, head->value);
		ft_printf("[%d]: value: %d | cost_a: %d | cost_b: %d\n", i, head->value, head->cost_a, head->cost_b);
		head = head->next;
		i++;
	}
}

void	ft_invert_list(t_deque *deque)
{
	t_node	*temp;
	t_node	*current;
	t_node	*next;

	if (deque->size == 0)
		return ;
	current = deque->top;
	next = deque->top->next;
	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = next;
		if (next)
			next = next->next;
	}
	temp = deque->top;
	deque->top = deque->bottom;
	deque->bottom = temp;
}

void	ft_reset_cost(t_deque *deque)
{
	t_node	*head;

	if (!deque || deque->size == 0)
		return ;
	head = deque->top;
	while (head)
	{
		head->cost_a = 0;
		head->cost_b = 0;
		head = head->next;
	}
}

size_t	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:36:51 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/09 15:31:47 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_deque_handler.h"
#include "includes/ft_utils_ps.h"
#include "includes/ft_utils_ds.h"

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
		if (*argv[i] == '\0')
			return (ft_to_free((void **) &values));
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
		ft_printf("[%d]: value: %d | ", i, head->value);
		ft_printf("cost_a: %d | cost_b: %d\n", head->cost_a, head->cost_b);
		head = head->next;
		i++;
	}
}

int	populate_list_with_args(t_deque **list, int argc, char *argv[])
{
	char	**values;
	t_node	*aux_node;
	int		i;

	values = ft_get_values(argc, argv);
	if (!values)
	{
		*list = NULL;
		return (1);
	}
	i = 0;
	while (values[i])
	{
		aux_node = ft_node_create(ft_atol(values[i]));
		if (!aux_node)
		{
			ft_free_str_vector(values);
			ft_free_deque(*list);
			return (1);
		}
		ft_deque_push_bottom(*list, aux_node);
		i++;
	}
	ft_free_str_vector(values);
	return (0);
}

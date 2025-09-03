/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:27:31 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 14:37:34 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_error_handler.h"

int	ft_not_is_only_number(char *value)
{
	int	i;

	if (!value || !*value)
		return (1);
	i = 0;
	if (value[i] == '+' || value[i] == '-')
		i++;
	if (!value[i])
		return (1);
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_validate_duplicate_values(char **values)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (values[i])
	{
		num_i = ft_atol(values[i]);
		j = i + 1;
		while (values[j])
		{
			num_j = ft_atol(values[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validade_values(char **values)
{
	int		i;
	long	value;

	if (!values[0])
		return (1);
	i = 0;
	while (values[i])
	{
		if (ft_not_is_only_number(values[i]))
			return (1);
		value = ft_atol(values[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (1);
		i++;
	}
	return (ft_validate_duplicate_values(values));
}

int	ft_handle_input_error(int argc, char *argv[])
{
	char	**values;
	int		error;

	if (argc == 1)
		return (1);
	values = ft_get_values(argc, argv);
	if (!values)
		return (1);
	error = ft_validade_values(values);
	ft_free_str_vector(values);
	return (error);
}

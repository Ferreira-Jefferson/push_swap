/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:27:31 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:49:54 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_error_handler.h"

int	ft_not_is_only_number(char *value)
{
	int	len_original;
	int	count_number;
	int	count_space;
	int	count_signal;

	len_original = ft_strlen(value);
	count_number = 0;
	count_space = 0;
	count_signal = 0;
	while (*value)
	{
		count_number += ft_isdigit(*value);
		count_space += ft_isspace(*value);
		if ((*value == '-' || *value == '+') && ft_isdigit(*(value + 1)))
			count_signal += 1;
		value++;
	}
	if (count_signal > 1)
		return (1);
	return ((count_number + count_space + count_signal) != len_original);
}

int	ft_validate_duplicate_values(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i])
	{
		j = i + 1;
		while (values[j])
		{
			if (ft_atoi(values[i]) == ft_atoi(values[j]))
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
	int		is_zero;
	int		len;

	i = 0;
	while (values[i])
	{
		if (ft_not_is_only_number(values[i]))
			return (1);
		value = ft_atol(values[i]);
		if (!value)
		{
			len = ft_strlen(values[i]);
			is_zero = (len <= 2 && *values[len - 1] == '0');
			if (!is_zero)
				return (1);
		}
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
	{
		ft_printf("Usage: program-name number_values");
		return (1);
	}
	values = ft_get_values(argc, argv);
	if (!values)
		return (1);
	error = ft_validade_values(values);
	ft_free_str_vector(values);
	return (error);
}

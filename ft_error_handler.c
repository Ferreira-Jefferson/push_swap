/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:27:31 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/17 17:22:12 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_handler.h"

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
		if (*value == '-' || *value == '+')
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

char	*ft_join_args(int argc, char *argv[])
{
	int		i;
	char	*values;
	char	*to_free;

	values = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		to_free = values;
		values = ft_strjoin(values, ft_strjoin(argv[i], " "));
		ft_to_free((void **) &to_free);
		if (!values)
			return (NULL);
		i++;
	}
	return (values);
}

int	ft_handle_input_error(int argc, char *argv[])
{
	char	**values;
	char	*arg_values;

	if (argc == 1)
	{
		ft_printf("Usage: program-name 1 2 3 ...");
		ft_printf(" OR program-name \"1 2 3 ...\".\n");
		return (1);
	}
	if (argc == 2)
		arg_values = argv[1];
	else
		arg_values = ft_join_args(argc, argv);
	values = ft_split(arg_values, ' ');
	return (ft_validade_values(values));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:00:18 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/01 18:09:41 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	int		signal;

	nb = 0;
	signal = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if ((nb > (LONG_MAX / 10))
			|| (nb == (LONG_MAX / 10) && (*nptr - '0') > (LONG_MAX % 10)))
		{
			if (signal == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return (nb * signal);
}

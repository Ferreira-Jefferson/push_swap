/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:00:18 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/17 13:08:37 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	unsigned long	nb;
	int				signal;

	if (*nptr == '\0')
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	signal = 1;
	if (*nptr == '+' || *nptr == '-' )
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	nb = 0;
	while (ft_isdigit(*nptr))
	{
		nb = (nb * 10) + (*nptr - '0');
		if (signal == -1 && nb >= LONG_MAX)
			return (LONG_MIN);
		if (nb > LONG_MAX)
			return (LONG_MAX);
		nptr++;
	}
	return (nb * signal);
}

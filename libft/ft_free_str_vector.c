/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:37:10 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/17 17:39:53 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_str_vector(char **str_vector)
{
	char	**aux;

	aux = str_vector;
	while (str_vector && *aux)
	{
		free(*aux);
		aux++;
	}
	free(str_vector);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:36:51 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 12:47:59 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_handler.h"

void	ft_print_list(t_deque *deque)
{
	size_t	i;
	t_node	*head;

	head = deque->top;
	i = 0;
	while (i < deque->size)
	{
		ft_printf("[%d]: %d\n", i, head->value);
		head = head->next;
		i++;
	}
}
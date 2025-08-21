/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:22:41 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:31:00 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	node = ft_detache_node_by_index(list_b, 0);
	if (!node)
		return ;
	ft_deque_push_top(list_a, node->value);
	ft_printf("pa\n");
}

void	pb(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	node = ft_detache_node_by_index(list_a, 0);
	if (!node)
		return ;
	ft_deque_push_top(list_b, node->value);
	ft_printf("pb\n");
}

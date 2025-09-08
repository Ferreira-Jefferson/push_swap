/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:22:41 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/08 11:39:31 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	node = ft_detache_node_by_index(list_b, 0);
	if (!node)
		return ;
	ft_deque_push_top(list_a, ft_node_create(node->value));
	free(node);
	ft_printf("pa\n");
}

void	pb(t_deque *list_a, t_deque *list_b)
{
	t_node	*node;

	node = ft_detache_node_by_index(list_a, 0);
	if (!node)
		return ;
	ft_deque_push_top(list_b, ft_node_create(node->value));
	free(node);
	ft_printf("pb\n");
}

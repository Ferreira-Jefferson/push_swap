/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:10:19 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 12:46:36 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (ft_handle_input_error(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Ok\n");

	t_deque *deque;

	deque = ft_deque_create();
	ft_deque_push_top(deque, 10);
	ft_deque_push_top(deque, 20);
	ft_deque_push_top(deque, 30);
	ft_deque_push_top(deque, 40);
	ft_deque_push_top(deque, 50);
	ft_print_list(deque);
	ft_invert_list(deque);
	ft_printf("\n");
	ft_print_list(deque);
	ft_printf("size: %d\n", deque->size);
	
	ft_printf("\n");
	ft_print_list(deque);
	t_node *detache = ft_detache_node_by_index(deque, 2);
	ft_printf("detache 2: %d\n", detache->value);
	ft_printf("top: %p | bottom: %p | size: %d\n", deque->top, deque->bottom, deque->size);
	ft_printf("\n");
	
	ft_print_list(deque);
	detache = ft_detache_node_by_index(deque, 1);
	ft_printf("detache 1: %d\n", detache->value);
	ft_printf("top: %p | bottom: %p | size: %d\n", deque->top, deque->bottom, deque->size);
	ft_printf("\n");
	
	ft_print_list(deque);
	detache = ft_detache_node_by_index(deque, 0);
	ft_printf("detache 0: %d\n", detache->value);
	ft_printf("top: %p | bottom: %p | size: %d\n", deque->top, deque->bottom, deque->size);
	ft_printf("\n");
	
	ft_clear_deque(deque);
	ft_print_list(deque);
	ft_to_free((void **) &deque);
	
	return (0);
}

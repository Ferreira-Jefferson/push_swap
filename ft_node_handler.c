/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:06:35 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 12:16:24 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node_handler.h"

t_node	*ft_node_create(int value)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_node_last(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

t_node	*ft_node_add_top(t_node *lst, t_node *node)
{
	if (!node)
		return (lst);
	if (!lst)
	{
		lst = node;
		return (lst);
	}
	lst->prev = node;
	node->next = lst;
	lst = node;
	return (lst);
}

t_node	*ft_node_add_bottom(t_node *lst, t_node *node)
{
	t_node	*last;

	if (!node)
		return (lst);
	if (!lst)
	{
		lst = node;
		return (lst);
	}
	last = ft_node_last(lst);
	node->prev = last;
	last->next = node;
	return (lst);
}

t_node	*ft_node_remove(t_node *lst, int value)
{
	t_node	*head;

	if (!lst)
		return (NULL);
	head = lst;
	while (head && head->value != value)
		head = head->next;
	if (!head)
		return (lst);
	if (head->prev)
		head->prev->next = head->next;
	else
		lst = head->next;
	if (head->next)
		head->next->prev = head->prev;
	ft_to_free((void **) &head);
	return (lst);
}

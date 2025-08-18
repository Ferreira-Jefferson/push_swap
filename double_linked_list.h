/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:09:26 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/18 10:08:22 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include "ft_node_handler.h"

typedef struct s_deque t_deque;

typedef struct s_deque {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_deque;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:07:10 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/18 10:09:15 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_HANDLER_H
# define FT_NODE_HANDLER_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node t_node;

typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

t_node	*ft_node_create(int value);
t_node	*ft_node_add_top(t_node *lst, t_node *node);
t_node	*ft_node_add_bottom(t_node *lst, t_node *node);
t_node	*ft_node_remove(t_node *lst, int value);
t_node	*ft_node_last(t_node *lst);

#endif
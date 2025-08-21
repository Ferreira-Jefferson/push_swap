/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:34:17 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 16:59:47 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include "ft_deque_handler.h"
# include "push_swap.h"

int		ft_is_it_ordered_by_top(t_deque *list);
int		ft_is_it_ordered_by_bottom(t_deque *list);
void	ft_sort_three(t_deque *list);

#endif
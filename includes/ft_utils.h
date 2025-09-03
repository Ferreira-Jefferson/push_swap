/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/03 13:22:54 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_deque_handler.h"

int		ft_abs(int value);
int		ft_equal_signs(int cost_a, int cost_b);
int		ft_get_min(t_deque *list_a);
void	ft_set_min_and_max(t_deque *list, int *min, int *max);

#endif
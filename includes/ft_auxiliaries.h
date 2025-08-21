/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/21 11:48:57 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUXILIARIES_H
# define FT_AUXILIARIES_H

# include "ft_deque_handler.h"

char	**ft_get_values(int argc, char *argv[]);
char	*ft_join_args(int argc, char *argv[]);
void	ft_print_list(t_deque *deque);
void	ft_invert_list(t_deque *deque);
void	ft_reset_cost(t_deque *deque);

#endif
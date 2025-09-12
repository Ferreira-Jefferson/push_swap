/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:12:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/09 15:25:47 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_PS_H
# define FT_UTILS_PS_H

# include "ft_deque_handler.h"

char	**ft_get_values(int argc, char *argv[]);
char	*ft_join_args(int argc, char *argv[]);
void	ft_print_list(t_deque *deque);
int		populate_list_with_args(t_deque **list, int argc, char *argv[]);

#endif
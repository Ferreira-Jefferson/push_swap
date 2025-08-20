/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:06:38 by jtertuli          #+#    #+#             */
/*   Updated: 2025/08/20 13:38:12 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_HANDLER_H
# define FT_ERROR_HANDLER_H

# include "libft/libft.h"
# include "ft_auxiliaries.h"

int		ft_not_is_only_number(char *value);
int		ft_validade_values(char **values);
int		ft_validate_duplicate_values(char **values);
int		ft_handle_input_error(int argc, char *argv[]);

#endif
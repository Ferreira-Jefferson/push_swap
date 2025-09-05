/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:18:01 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/05 08:42:19 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker_bonus.h"
#include "includes/ft_error_handler.h"

int	main(int argc, char *argv[])
{	
	t_deque	*list_a;

	if (argc == 1)
		return (0);
	if (ft_handle_input_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	list_a = ft_deque_create();
	populate_list_with_args(list_a, argc, argv);
	if (!list_a)
		return (1);
	if (ft_handler_moves(list_a))
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (ft_is_it_ordered_by_top(list_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_free_deque(list_a);
	return (0);
}

int	ft_handler_moves(t_deque *list_a)
{
	char	*input;
	t_deque	*list_b;
	int		error;
	char	*move;

	error = 0;
	list_b = ft_deque_create();
	input = get_next_line(0);
	while (input)
	{
		if (!ft_is_valid_move(input))
		{
			error = 1;
			break ;
		}
		move = ft_strtrim(input, "\n");
		ft_make_move(move, list_a, list_b);
		ft_to_free((void **) &move);
		ft_to_free((void **) &input);
		input = get_next_line(0);
	}
	ft_to_free((void **) &input);
	ft_to_free((void **) &list_b);
	return (error);
}

void	ft_make_move(char *move, t_deque *list_a, t_deque *list_b)
{
	if (ft_isequal("sa", move))
		swap(list_a, NULL);
	if (ft_isequal("sb", move))
		swap(NULL, list_b);
	if (ft_isequal("ss", move))
		swap(list_a, list_b);
	if (ft_isequal("pa", move))
		push(move, list_a, list_b);
	if (ft_isequal("pb", move))
		push(move, list_a, list_b);
	if (ft_isequal("ra", move))
		rotate(list_a, NULL);
	if (ft_isequal("rb", move))
		rotate(NULL, list_b);
	if (ft_isequal("rr", move))
		rotate(list_a, list_b);
	if (ft_isequal("rra", move))
		reverse(list_a, NULL);
	if (ft_isequal("rrb", move))
		reverse(NULL, list_b);
	if (ft_isequal("rrr", move))
		reverse(list_a, list_b);
}

int	ft_is_valid_move(char *input)
{
	char	**moves;
	char	*move;
	int		is_valid;
	int		i;

	moves = ft_split(input, ' ');
	if (!moves || moves[0] == NULL || moves[1] != NULL)
	{
		ft_free_str_vector(moves);
		return (0);
	}
	i = 0;
	is_valid = 0;
	move = ft_strtrim(moves[0], "\n");
	ft_free_str_vector(moves);
	moves = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (moves[i])
	{
		if (ft_isequal(move, moves[i]))
				is_valid = 1;
		i++;
	}
	ft_free_str_vector(moves);
	ft_to_free((void **) &move);
	return (is_valid);
}

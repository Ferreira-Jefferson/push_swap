#include "includes/ft_core_calculation_cost.h"


static void	ft_set_min_and_max(t_deque *list, int *min, int *max)
{
	t_node	*head;

	*min = list->top->value;
	*max = list->top->value;
	head = list->top;
	while (head)
	{
		if (head->value > *max)
			*max = head->value;
		if (head->value < *min)
			*min = head->value;
		head = head->next;
	}
}

size_t	ft_index_to_insert_in_b_reverse(t_deque *list_a, int value)
{
	t_node	*current;
	size_t	index;
	int		min;
	int		max;

	if (!list_a || list_a->size == 0)
		return (0);
	ft_set_min_and_max(list_a, &min, &max);
	current = list_a->top;
	index = 0;
	while (current->next)
	{
		if ((value < min || value > max) && current->value == max)
			return (index + 1);
		if (current->value < value && value < current->next->value)
			return (index + 1);
		current = current->next;
		index++;
	}
	return (0);
}

void	ft_calculate_cost_b_reverse(t_deque *list_a, t_deque *list_b)
{
	int index;

	if (!list_a || !list_b || list_b->size == 0)
		return ;
	index = ft_index_to_insert_in_b_reverse(list_a, list_b->top->value);

	if (index <= (int) list_a->size / 2)
		list_b->top->cost_a = index;
	else
		list_b->top->cost_a = -(list_a->size - index);

	list_b->top->cost_b = 0;
}

size_t	ft_index_to_insert_in_b(t_deque *list_b, int value)
{
	t_node	*current;
	size_t	index;
	size_t	index_to_return;
	int		min;
	int		max;

	current = list_b->top;
	ft_set_min_and_max(list_b, &min, &max);
	index_to_return = 0;
	index = 0;
	while (current)
	{
		if ((value > max || value < min) && current->value == max)
			return (index);
		else if (current->value >= value && (current->next && value > current->next->value))
			return (index + 1);
		current = current->next;
		index++;
	}
	return (index_to_return);
}

int	ft_calculate_cost_a(t_deque *list, int index)
{
	t_node	*head;
	size_t	current_index;

	if (index >= 0)
	{
		if (index <= (int) list->size / 2)
			return (index);
		else
			return (-(list->size  - index));
	}
	current_index = 0;
	head = list->top;
	while (head)
	{
		head->cost_a = ft_calculate_cost_a(list, current_index);
		head = head->next;
		current_index++;
	}
	return (0);
}

int	ft_calculate_cost_b(t_deque *list_a, t_deque *list_b)
{
	t_node	*head;
	int		index;

	head = list_a->top;
	while (head)
	{
		index = ft_index_to_insert_in_b(list_b, head->value);
		if (index <= (int) list_b->size / 2)
			head->cost_b = index;
		else
			head->cost_b = -(list_b->size - index);
		head = head->next;
	}
	return (0);
}

#include  "includes/ft_specific_movements.h"

void	ft_sort_three(t_deque *list)
{
	int	top;
	int	middle;
	int	bottom;

	if (ft_is_it_ordered_by_top(list))
		return ;
	if (ft_is_it_ordered_by_bottom(list))
	{
		ra(list, 0);
		sa(list, 0);
		return ;
	}
	middle = list->top->next->value;
	top = list->top->value;
	bottom = list->bottom->value;
	if (top > middle && top < bottom)
		return (sa(list, 0));
	if (top > middle && top > bottom)
		return (ra(list, 0));
	ra(list, 0);
	ft_sort_three(list);
}
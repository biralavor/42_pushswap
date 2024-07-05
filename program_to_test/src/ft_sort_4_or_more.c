/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5_or_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:29 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:12:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four_or_more_nbr(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_b_all_but_three(stack_a, stack_b);
	ft_sort_a_with_three_nbrs(stack_a);
	while (*stack_b)
	{
		ft_lst_get_target_position(stack_a, stack_b);
		ft_lst_get_cost(stack_a, stack_b);
		ft_lst_calc_cheapest_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_lst_shift_stack(stack_a);
}

void	ft_lst_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	size_a = ft_lst_size(temp_a);
	size_b = ft_lst_size(temp_b);
	ft_lst_map_actual_position(stack_a);
	ft_lst_map_actual_position(stack_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->origin;
		if (temp_b->origin > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->origin) * -1;
		temp_b->cost_a = temp_b->target;
		if (temp_b->target > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target) * -1;
		temp_b = temp_b->next;
	}
}

void	ft_lst_calc_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int		cost_a;
	int		cost_b;
	int		cheapest;
	t_stack	*temp_b;

	cheapest = INT_MAX;
	ft_lst_map_actual_position(stack_a);
	ft_lst_map_actual_position(stack_b);
	temp_b = (*stack_b);
	while (temp_b)
	{
		if ((abs_nbr(temp_b->cost_a) + abs_nbr(temp_b->cost_b))
			< abs_nbr(cheapest))
		{
			cheapest = abs_nbr(temp_b->cost_b) + abs_nbr(temp_b->cost_a);
			cost_a = temp_b->cost_a;
			cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	ft_do_move_after_cheapest(stack_a, stack_b, cost_a, cost_b);
}

int	abs_nbr(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_do_move_after_cheapest(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rev_rotate_ab_with_cost(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_ab_with_cost(stack_a, stack_b, &cost_a, &cost_b);
	ft_rotate_a_with_cost(stack_a, &cost_a);
	ft_rotate_b_with_cost(stack_b, &cost_b);
	ft_do_push_a(stack_a, stack_b);
}

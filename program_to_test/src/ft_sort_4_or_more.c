/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_or_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:29 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 11:38:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four_or_more_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_b_all_but_three(stack_a, stack_b);
	ft_sort_three_nbrs(stack_a);
	ft_lst_printf_data_content("stack_a before get-target:", *stack_a);
	ft_lst_printf_data_content("stack_b before get-target:", *stack_b);
	while (*stack_b)
	{
		ft_lst_get_target_position(stack_a, stack_b);
		ft_lst_get_cost(stack_a, stack_b);
		ft_lst_do_cheapest_move(stack_a, stack_b);
	}
	ft_lst_printf_data_content("stack_a after get-target:", *stack_a);
	ft_lst_printf_data_content("stack_b after get-target:", *stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_lst_shift_stack(stack_a);
}

void	ft_push_b_all_but_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	index;

	stack_size = ft_lst_size(*stack_a);
	pushed = 0;
	index = 0;
	while ((stack_size > 6) && (index < stack_size)
		&& (pushed < stack_size / 2))
	{
		if ((*stack_a)->final_pos <= (stack_size / 2))
		{
			ft_do_push_b(stack_a, stack_b);
			pushed++;
		}
		else
			ft_do_rotate_a(stack_a);
		index++;
	}
	while (stack_size - pushed > 3)
	{
		ft_do_push_b(stack_a, stack_b);
		pushed++;
	}
	*stack_b = ft_lst_delat_end(*stack_b);
}

void	ft_lst_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = ft_lst_size(temp_a);
	size_b = ft_lst_size(temp_b);
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

void	ft_lst_do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int		cost_a;
	int		cost_b;
	int		cheapest;
	t_stack	*temp_b;

	temp_b = *stack_b;
	cheapest = INT_MAX;
	while (temp_b)
	{
		if ((temp_b->cost_a + temp_b->cost_b) < cheapest)
		{
			cheapest = temp_b->cost_b + temp_b->cost_a;
			cost_a = temp_b->cost_a;
			cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	ft_do_move_after_cheapest(stack_a, stack_b, cost_a, cost_b);
}

void	ft_lst_shift_stack(t_stack **stack_a)
{
	int	lowest_final_pos;
	int	stack_size;

	stack_size = ft_lst_size(*stack_a);
	lowest_final_pos = ft_lst_map_lowest_final_position(stack_a);
	if (lowest_final_pos < stack_size / 2)
	{
		while (lowest_final_pos < stack_size)
		{
			ft_do_reverse_rotate_a(stack_a);
			lowest_final_pos++;
		}
	}
	else
	{
		while (lowest_final_pos > 0)
		{
			ft_do_rotate_a(stack_a);
			lowest_final_pos--;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:29 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:10:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if ((*stack_b)->next && (*stack_b)->final_pos < (*stack_b)->next->final_pos)
				ft_do_rotate_b(stack_b);
			if ((*stack_b)->next && (*stack_b)->final_pos > (*stack_b)->next->final_pos)
				ft_do_reverse_rotate_b(stack_b);
		}
		else
			ft_do_rotate_a(stack_a);
		index++;
	}
	while ((stack_size - pushed) > 3)
	{
		ft_do_push_b(stack_a, stack_b);
		pushed++;
	}
}

void	ft_lst_shift_stack(t_stack **stack_a)
{
	int	lowest_final_pos;
	int	stack_size;

	stack_size = ft_lst_size(*stack_a);
	lowest_final_pos = ft_lst_map_lowest_final_position(stack_a);
	if (lowest_final_pos > stack_size / 2)
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

int	ft_lst_map_lowest_final_position(t_stack **stack)
{
	int		lowest_final_pos;
	int		lowest_position;
	t_stack	*temp;

	temp = ft_lst_goto_head(*stack);
	ft_lst_map_actual_position(stack);
	lowest_final_pos = INT_MAX;
	lowest_position = temp->origin;
	while (temp)
	{
		if (temp->final_pos < lowest_final_pos)
		{
			lowest_final_pos = temp->final_pos;
			lowest_position = temp->origin;
		}
		temp = temp->next;
	}
	return (lowest_position);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/04 10:29:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_actual_position(t_stack **stack)
{
	int	actual_position;

	actual_position = 0;
	*stack = ft_lst_goto_head(*stack);
	while ((*stack)->next != NULL)
	{
		(*stack)->origin = actual_position;
		(*stack) = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			actual_position++;
			(*stack)->origin = actual_position;
		}
		actual_position++;
	}
	*stack = ft_lst_goto_head(*stack);
}

void	ft_lst_map_final_pos(t_stack **stack, int stack_size)
{
	int		final_pos;
	t_stack	*temp;
	t_stack	*highest;

	while (--stack_size > 0)
	{
		temp = *stack;
		final_pos = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->nbr == INT_MIN && temp->final_pos == 0)
				temp->final_pos = 1;
			if (temp->nbr > final_pos && temp->final_pos == 0)
			{
				final_pos = temp->nbr;
				highest = temp;
				temp = *stack;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->final_pos = stack_size;
	}
}

int	ft_lst_get_target(t_stack **stack_a, int b_end_pos,
							int target_end_pos, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->final_pos > b_end_pos && temp_a->final_pos < target_end_pos)
		{
			target_end_pos = temp_a->final_pos;
			target_pos = temp_a->origin;
		}
		temp_a = temp_a->next;
	}
	if (target_end_pos != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->final_pos < target_end_pos)
		{
			target_end_pos = temp_a->final_pos;
			target_pos = temp_a->origin;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	ft_lst_get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		target_position;
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_lst_map_actual_position(stack_a);
	ft_lst_map_actual_position(stack_b);
	target_position = 0;
	while (temp_b)
	{
		target_position = ft_lst_get_target(stack_a, temp_b->final_pos,
				INT_MAX, target_position);
		temp_b->target = target_position;
		temp_b = temp_b->next;
	}
}

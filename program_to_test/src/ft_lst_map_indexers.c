/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 11:15:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_original_position(t_stack **stack)
{
	int	original_position;

	original_position = 0;
	while ((*stack)->next != NULL)
	{
		original_position++;
		(*stack)->origin = original_position;
		(*stack) = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			original_position++;
			(*stack)->origin = original_position;
		}
	}
	*stack = ft_lst_goto_head(*stack);
}

void	ft_lst_map_final_pos(t_stack **stack, int stack_size)
{
	int		final_pos;
	t_stack	*target;
	t_stack	*highest;

	while (--stack_size > 0)
	{
		target = *stack;
		final_pos = INT_MIN;
		highest = NULL;
		while (target)
		{
			if (target->nbr == INT_MIN && target->final_pos == 0)
				target->final_pos = 1;
			if (target->nbr > final_pos && target->final_pos == 0)
			{
				final_pos = target->nbr;
				highest = target;
				target = *stack;
			}
			else
				target = target->next;
		}
		if (highest != NULL)
			highest->final_pos = stack_size;
	}
}

int	ft_lst_map_lowest_final_position(t_stack **stack)
{
	int		lowest_final_pos;
	int		lowest_position;
	t_stack	*temp;

	temp = *stack;
	lowest_final_pos = INT_MAX;
	ft_lst_map_original_position(stack);
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

int	ft_lst_get_target(t_stack **stack_a, int b_final_pos,
							int target_final_pos, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->final_pos > b_final_pos && temp_a->final_pos < target_final_pos)
		{
			target_final_pos = temp_a->final_pos;
			target_pos = temp_a->origin;
		}
		temp_a = temp_a->next;
	}
	if (target_final_pos != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->final_pos < target_final_pos)
		{
			target_final_pos = temp_a->final_pos;
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
	ft_lst_map_original_position(stack_a);
	ft_lst_map_original_position(stack_b);
	target_position = 0;
	while (temp_b)
	{
		target_position = ft_lst_get_target(stack_a, temp_b->final_pos,
				INT_MAX, target_position);
		temp_b->target = target_position;
		temp_b = temp_b->next;
	}
}

// void	ft_lst_map_final_pos_by_argv(t_stack **stack, char **argv)
// {
// 	int		final_pos;
// 	int		pos;
// 	char	**argv_splited;
// 	t_stack	*temp;

// 	final_pos = 0;
// 	pos = 0;
// 	final_pos = 0;
// 	temp = *stack;
// 	argv_splited = ft_split(*argv, ' ');
// 	while ((argv_splited[pos] != NULL) && (temp->next != NULL))
// 	{
// 		if (ft_atoi(argv_splited[pos]) > ft_atoi(argv_splited[pos + 1]))
// 			temp->final_pos = final_pos++;
//		temp = temp->next;
// 	}
// }

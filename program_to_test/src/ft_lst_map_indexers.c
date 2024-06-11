/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/11 18:04:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_position(t_stack **stack)
{
	int	pos;

	pos = 0;
	while ((*stack)->next != NULL)
	{
		pos++;
		(*stack)->pos = pos;
		(*stack) = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			pos++;
			(*stack)->pos = pos;
		}
	}
	*stack = ft_lst_goto_head(*stack);
}

void	ft_lst_map_weight(t_stack **stack, int stack_size)
{
	int		weight;
	t_stack	*target;
	t_stack	*highest;
	
	while (--stack_size > 0)
	{
		target = *stack;
		weight = INT_MIN;
		highest = NULL;
		while (target)
		{
			if (target->nbr == INT_MIN && target->weight == 0)
				target->weight = 1;
			if (target->nbr > weight && target->weight == 0)
			{
				weight = target->nbr;
				highest = target;
				target = *stack;
			}
			else
				target = target->next;
		}
		if (highest != NULL)
			highest->weight = stack_size;
	}
}

int	ft_lst_map_lowest_weight_position(t_stack **stack)
{
	int		lowest_weight;
	int		lowest_position;
	t_stack	*temp;

	temp = *stack;
	lowest_weight = INT_MAX;
	lowest_position = temp->pos;
	while (temp)
	{
		if (temp->weight < lowest_weight)
		{
			lowest_weight = temp->weight;
			lowest_position = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_position);
}

int	ft_lst_get_target_nbr(t_stack **stack_a, int b_weight,
							int target_weight, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->weight > b_weight && temp_a->weight < target_weight)
		{
			target_weight = temp_a->weight;
			target_pos = temp_a->pos;
		}
	}
	if (target_weight != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->weight < target_weight)
		{
			target_weight = temp_a->weight;
			target_pos = temp_a->pos;
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
	ft_lst_map_position(stack_a);
	ft_lst_map_position(stack_b);
	target_position = 0;
	while (temp_b)
	{
		target_position = ft_lst_get_target_nbr(stack_a, temp_b->weight,
												INT_MAX, target_position);
		temp_b->target = target_position;
		temp_b = temp_b->next;
	}
	
}

// void	ft_lst_map_weight_by_argv(t_stack **stack, char **argv)
// {
// 	int		weight;
// 	int		pos;
// 	char	**argv_splited;
// 	t_stack	*temp;

// 	weight = 0;
// 	pos = 0;
// 	weight = 0;
// 	temp = *stack;
// 	argv_splited = ft_split(*argv, ' ');
// 	while ((argv_splited[pos] != NULL) && (temp->next != NULL))
// 	{
// 		if (ft_atoi(argv_splited[pos]) > ft_atoi(argv_splited[pos + 1]))
// 			temp->weight = weight++;
//		temp = temp->next;
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 12:07:24 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_all_indexers(t_stack *stack)
{
	ft_lst_map_position(stack);
	ft_lst_map_weight(&stack);
}

void	ft_lst_map_position(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack->next != NULL)
	{
		pos++;
		stack->pos = pos;
		stack = stack->next;
		if (stack->next == NULL)
		{
			pos++;
			stack->pos = pos;
		}
	}
	stack = ft_lst_goto_head(stack);
}

void	ft_lst_map_weight(t_stack **stack)
{
	int		weight;
	t_stack	*target;
	t_stack	*compare_node;
	
	target = *stack;
	weight = 0;
	while (target != NULL && target->next != NULL)
	{
		compare_node = target->next;
		while (compare_node != NULL)
		{
			if (target->nbr > compare_node->nbr)
				weight++;
			compare_node = compare_node->next;
		}
		target->weight = weight;
		target = target->next;
	}
}

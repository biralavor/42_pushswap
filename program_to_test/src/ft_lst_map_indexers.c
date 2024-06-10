/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 11:24:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_all_indexers(t_stack *stack)
{
	ft_lst_map_position(stack);
	// ft_lst_map_weight(&stack);
}

void	ft_lst_map_position(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack->next != NULL)
	{
		pos++;
		(*stack).pos = pos;
		stack = stack->next;
		if (stack->next == NULL)
		{
			pos++;
			(*stack).pos = pos;
		}
	}
	stack = ft_lst_goto_head(stack);
}

// void	ft_lst_map_weight(t_stack **stack)
// {
// 	int		weight;
// 	int		target;
// 	int		tocompare;
// 	t_stack	*temp;
	
// 	weight = 0;
// 	*stack = ft_lst_goto_head(*stack);
// 	temp = *stack;
// 	target = temp->nbr;
// 	tocompare = (*stack)->next->nbr;
// 	while ((temp != NULL) && (temp->next != NULL) && ((*stack)->next != NULL)
// 			&& (weight <= ft_lst_size(*stack)))
// 	{
// 		while ((*stack)->next && (*stack)->next->nbr)
// 		{
// 			if (target > tocompare)
// 				weight++;
// 			(*stack)->weight = weight;
// 			if ((*stack)->next != NULL)
// 			{
// 				(*stack) = (*stack)->next;
// 				tocompare = (*stack)->nbr;
// 				ft_printf("tocompare = %d\n", tocompare);
// 			}
// 		}
// 		temp = temp->next;
// 		target = temp->nbr;
// 		ft_printf("(*stack)->weight  = %d\n", (*stack)->weight);
// 		ft_printf("target nbr = %d\n", target);
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/20 11:35:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_be_pushed;

	if (NULL == *stack_b)
		return ;
	to_be_pushed = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (NULL == *stack_a)
	{
		*stack_a = to_be_pushed;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
	{
		to_be_pushed->next = *stack_a;
		to_be_pushed->next->prev = to_be_pushed;
		*stack_a = to_be_pushed;
	}
	(*stack_a) = ft_lst_goto_head(*stack_a);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_be_pushed;

	if (NULL == *stack_a)
		return ;
 	to_be_pushed = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if ((*stack_a))
		(*stack_a)->prev = NULL;
	if (NULL == (*stack_b))
	{
		(*stack_b) = to_be_pushed;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
	{
		to_be_pushed->next = (*stack_b);
		to_be_pushed->next->prev = to_be_pushed;
		(*stack_b) = to_be_pushed;
	}
	(*stack_b) = ft_lst_goto_head(*stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_be_pushed;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	to_be_pushed = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if ((*stack_b))
		(*stack_b)->prev = NULL;
	to_be_pushed->next = NULL;
	to_be_pushed->prev = NULL;
	to_be_pushed->next = (*stack_a);
	(*stack_a)->prev = to_be_pushed;
	(*stack_a) = ft_lst_goto_head(*stack_a);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_be_pushed;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	to_be_pushed = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if ((*stack_a))
		(*stack_a)->prev = NULL;
	to_be_pushed->next = NULL;
	to_be_pushed->prev = NULL;
	to_be_pushed->next = (*stack_b);
	(*stack_b)->prev = to_be_pushed;
	(*stack_b) = ft_lst_goto_head(*stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/19 14:37:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	// int	temp;

	// if (NULL == stack || NULL == (*stack))
	// 	return ;
	// temp = (*stack)->nbr;
	// (*stack)->nbr = (*stack)->next->nbr;
	// (*stack)->next->nbr = temp;

	if (NULL == stack || NULL == (*stack))
		return ;
	(*stack) = (*stack)->next;
	(*stack)->prev->prev = (*stack);
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	ft_swap(&a);
	ft_swap(&b);
	stack_a = &a;
	stack_b = &b;
}

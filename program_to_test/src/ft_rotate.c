/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:48:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 10:56:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*	rotate:
	*	the top element is sent do the bottom
	*/
void	ft_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (NULL == stack || NULL == *stack || ft_lst_size(*stack) == 1)
		return ;
	last_node = ft_lst_goto_end(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (NULL == stack_a || NULL == stack_b || *stack_a == NULL
		|| *stack_b == NULL || ft_lst_size(*stack_a) == 1
		|| ft_lst_size(*stack_b) == 1)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (NULL == stack || NULL == *stack || ft_lst_size(*stack) == 1)
		return ;
	last_node = ft_lst_goto_end(*stack);
	last_node->prev->next = NULL;
	last_node->next = (*stack);
	last_node->prev = NULL;
	*stack = last_node;
	(*stack)->next->prev = last_node;
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (NULL == stack_a || NULL == stack_b || *stack_a == NULL 
		|| *stack_b == NULL || ft_lst_size(*stack_a) == 1 
		|| ft_lst_size(*stack_b) == 1)
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

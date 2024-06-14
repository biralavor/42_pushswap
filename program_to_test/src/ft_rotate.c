/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:48:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/14 17:40:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*	rotate:
	*	the top element is sent do the bottom
	*/
void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node = ft_lst_goto_end(*stack);
	temp->next = NULL;
	last_node->next = temp;
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_b == NULL)
		|| ((*stack_a)->next == NULL || (*stack_b)->next == NULL))
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (NULL == *stack || NULL == (*stack)->next || ft_lst_size(*stack) < 2)
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
	if (*stack_a == NULL || (*stack_b == NULL)
		|| ((*stack_a)->next == NULL || (*stack_b)->next == NULL))
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/22 11:34:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_init(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_lst_goto_end(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list && (list->next != NULL))
		list = list->next;
	return (list);
}

t_stack	*ft_lst_addto_end(t_stack *list, t_stack *new)
{
	t_stack	*temp;

	if (!list)
	{
		list = new;
		return (list);
	}
	if (!new)
		return (list);
	temp = ft_lst_goto_end(list);
	temp->next = new;
	new->prev = temp;
	return (list);
}

void	ft_swap(t_stack **stack)
{
	int	temp;

	if(*stack == NULL || (*stack)->next == NULL)
		return ;	
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp;
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

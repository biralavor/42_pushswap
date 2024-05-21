/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/21 15:41:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_init(int value)
{
	t_stack *new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_lstend_int(t_stack *list, int value)
{
	t_stack	*current_node;
	t_stack	*new_end;

	if ((list == NULL) || (ft_lstsize_int((t_list *)list) == 1))
	{
		list = ft_lst_init(value);
		return (list);
	}
	current_node = list;
	while (current_node->next != NULL)
		current_node = current_node->next;
	new_end = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_end == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_end->nbr = value;
	new_end->prev = current_node;
	new_end->next = NULL;
	current_node->next = new_end;
	return (list);
}

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if(*stack == NULL || (*stack)->next == NULL)
		return ;	
	first = *stack;
	second = *stack;
	second = second->next;
	temp = first->nbr;
	first->nbr = second->nbr;
	first->next->nbr = temp;
	*stack = first;
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	ft_swap(&a);
	ft_swap(&b);
	stack_a = &a;
	stack_b = &b;
}






int	push_add(int a, int b)
{
	return (a + b);
}

int push_subtract(int a, int b)
{
	return (a - b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 12:34:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*ft_lstend_int(t_stack_a *list, int value)
{
	t_stack_a	*new_end_node;
	t_stack_a	*current_node;

	if (list == NULL)
		return (NULL);
	new_end_node = (t_stack_a *)ft_calloc(1, sizeof(t_stack_a));
	if (new_end_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_end_node->nbr = value;
	new_end_node->next = NULL;
	current_node = list;
	while (current_node->next != NULL)
	{
		current_node->prev = current_node;
		current_node = current_node->next;
	}
	current_node->next = new_end_node;
	list = current_node;
	return (list);
}

void	swap_a(t_stack_a **stack_a)
{
	t_stack_a	*first;
	t_stack_a	*last;
	int			temp;

	if(*stack_a == NULL || (*stack_a)->next == NULL)
		return ;	
	first = *stack_a;
	last = *stack_a;
	temp = 0;
	while (last->next != NULL)
	{
		last->prev = last;
		last = last->next;
	}
	temp = first->nbr;
	first->nbr = last->nbr;
	last->nbr = temp;
}

int	push_add(int a, int b)
{
	return (a + b);
}

int push_subtract(int a, int b)
{
	return (a - b);
}

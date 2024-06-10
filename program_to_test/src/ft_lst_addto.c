/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/08 18:05:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_addto_end(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return (*stack);
	if (!*stack)
	{
		new->next = NULL;
		*stack = new;
		return (new);
	}
	tail = ft_lst_goto_end(*stack);
	tail->next = new;
	new->prev = tail;
	return (*stack);
}

t_stack	*ft_lst_addto_begin(t_stack **stack, t_stack *new)
{
	t_stack *head;

	if (!new)
		return (*stack);
	if (!*stack)
	{
		new->next = NULL;
		*stack = new;
		return (new);
	}
	head = ft_lst_goto_head(*stack);
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	return (new);
}

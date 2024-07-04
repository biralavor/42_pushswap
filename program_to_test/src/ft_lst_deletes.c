/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_deletes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 21:00:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_delat_begin(t_stack *stack)
{
	t_stack	*temp;

	stack = ft_lst_goto_head(stack);
	stack->next->prev = NULL;
	temp = stack->next;
	free(stack);
	return (temp);
}

t_stack	*ft_lst_delat_end(t_stack *stack)
{
	t_stack	*second_last_node;

	second_last_node = NULL;
	second_last_node = ft_lst_goto_before_end(stack);
	free(second_last_node->next);
	second_last_node->next = NULL;
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/22 14:53:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	tobe_pushed;
	// t_stack	*temp;
	
	if(*stack_b == NULL)
		return ;
	tobe_pushed = (*stack_b)->nbr;
	*stack_a = ft_lst_addto_begin(*stack_a, ft_lst_init(tobe_pushed));
	// (*stack_a)->nbr = (*stack_b)->nbr;
	// temp = (t_stack *)ft_calloc(1, sizeof(t_stack));
	// temp->nbr = tobe_pushed;
	// temp->next = NULL;
	// while ((*stack_b)->next != NULL)
	// {
	// 	temp->nbr = (*stack_b)->nbr;
	// }
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/22 12:25:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	tobe_pushed;
	t_stack	*temp;
	
	if(*stack_b == NULL)
		return ;
	tobe_pushed = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_b)->nbr;
	temp = (t_stack *)ft_calloc(1, sizeof(t_stack));
	while ((*stack_b)->next != NULL)
	{
		temp->nbr = (*stack_b)->nbr;
	}
	
}

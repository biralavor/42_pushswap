/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/05 18:52:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	tobe_pushed;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	tobe_pushed = (*stack_b)->nbr;
	*stack_a = ft_lst_addto_begin(stack_a, ft_lst_init(tobe_pushed));
	*stack_b = ft_lst_delat_begin(*stack_b);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	tobe_pushed;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	tobe_pushed = (*stack_a)->nbr;
	*stack_b = ft_lst_addto_begin(stack_b, ft_lst_init(tobe_pushed));
	*stack_a = ft_lst_delat_begin(*stack_a);
}

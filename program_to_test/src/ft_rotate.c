/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:48:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/23 17:09:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->nbr;
	*stack = ft_lst_addto_end(*stack, ft_lst_init(temp));
	*stack = ft_lst_delat_begin(*stack);
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
	int		temp;
	// t_stack	*ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;

	temp = ft_lst_goto_end(*stack)->nbr;
	*stack = ft_lst_addto_begin(*stack, ft_lst_init(temp));
	*stack = ft_lst_delat_end(*stack);
}

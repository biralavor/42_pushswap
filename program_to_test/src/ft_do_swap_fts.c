/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_swap_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:40:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap_a(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	ft_do_swap_b(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ft_do_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lst_size(*stack_a) == 1 || ft_lst_size(*stack_b) == 1)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

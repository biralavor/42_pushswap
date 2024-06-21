/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_push_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/21 11:30:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_push_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_lst_printf_data_content("after mov stack_a:", *stack_a);
	ft_printf("\n");
	ft_lst_printf_data_content("after mov stack_b:", *stack_b);
	ft_push_a(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	ft_do_push_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_b(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

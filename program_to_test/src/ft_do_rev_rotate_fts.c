/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rev_rotate_fts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/21 11:31:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_reverse_rotate_a(t_stack **stack)
{
	ft_lst_printf_data_content("after mov stack_a:", *stack);
	ft_printf("\n");
	ft_reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	ft_do_reverse_rotate_b(t_stack **stack)
{
	ft_lst_printf_data_content("after mov stack_b:", *stack);
	ft_printf("\n");
	ft_reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_do_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_lst_printf_data_content("after mov stack_a:", *stack_a);
	ft_printf("\n");
	ft_lst_printf_data_content("after mov stack_b:", *stack_b);
	ft_reverse_rotate_ab(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}

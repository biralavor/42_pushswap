/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_swap_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/04 18:28:33 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap_a(t_stack *stack)
{
	ft_swap(&stack);
	ft_putstr_fd("sa\n", 1);
}

void	ft_do_swap_b(t_stack *stack)
{
	ft_swap(&stack);
	ft_putstr_fd("sb\n", 1);
}

void	ft_do_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(&stack_a);
	ft_swap(&stack_b);
	ft_putstr_fd("ss\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rotate_fts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/04 18:58:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate_a(t_stack *stack)
{
	ft_rotate(&stack);
	ft_putstr_fd("ra\n", 1);
}

void	ft_do_rotate_b(t_stack *stack)
{
	ft_rotate(&stack);
	ft_putstr_fd("rb\n", 1);
}

void	ft_do_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_ab(&stack_a, &stack_b);
	ft_putstr_fd("rr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rev_rotate_fts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:49:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_reverse_rotate_a(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	ft_do_reverse_rotate_b(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_do_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lst_size(*stack_a) == 1 || ft_lst_size(*stack_b) == 1)
		return ;
	ft_reverse_rotate_ab(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}

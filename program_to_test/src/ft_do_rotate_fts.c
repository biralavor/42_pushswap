/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rotate_fts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:24:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:49:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate_a(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	ft_do_rotate_b(t_stack **stack)
{
	if (ft_lst_size(*stack) == 1)
		return ;
	ft_rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	ft_do_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lst_size(*stack_a) == 1 || ft_lst_size(*stack_b) == 1)
		return ;
	ft_rotate_ab(stack_a, stack_b);
	ft_putstr_fd("rr\n", 1);
}

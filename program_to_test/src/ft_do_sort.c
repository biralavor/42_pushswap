/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:46:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 14:03:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_is_sorted(*stack_a))
	{
		if (ft_lst_size(*stack_a) == 2)
			ft_sort_two_nbrs(stack_a);
		else if (ft_lst_size(*stack_a) == 3)
			ft_sort_three_nbrs(stack_a);
		else
		{
			ft_sort_four_or_more_nbrs(stack_a, stack_b);
		}
	}
}

void	ft_do_move_after_cheapest(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_do_reverse_rotate_ab(stack_a, stack_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_do_rotate_ab(stack_a, stack_b);
	ft_do_rotate_a(stack_a);
	ft_do_rotate_b(stack_b);
	ft_do_push_a(stack_a, stack_b);
}

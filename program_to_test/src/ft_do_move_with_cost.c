/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_move_with_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:16:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/26 12:20:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_ab_with_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_do_reverse_rotate_ab(stack_a, stack_b);
	}
}

void	ft_rotate_ab_with_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_do_rotate_ab(stack_a, stack_b);
	}
}

void	ft_rotate_a_with_cost(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ft_do_rotate_a(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			ft_do_reverse_rotate_a(stack_a);
			(*cost_a)++;
		}
	}
}

void	ft_rotate_b_with_cost(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			ft_do_rotate_a(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			ft_do_reverse_rotate_a(stack_b);
			(*cost_b)++;
		}
	}
}

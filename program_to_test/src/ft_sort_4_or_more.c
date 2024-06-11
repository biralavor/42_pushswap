/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_or_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:29 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/11 18:48:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_all_indexers(t_stack **stack)
{
	int	stack_size;

	stack_size = ft_lst_size(*stack);
	ft_lst_map_position(stack);
	ft_lst_map_weight(stack, stack_size);
}

/*
* TODO after line 40:
*	while (*stack_b)
*	{
*		ft_lst_get_target_position(stack_a, stack_b);
*		ft_lst_get_cost(stack_a, stack_b);
*		ft_lst_do_cheapest_move(stack_a, stack_b);
*	}
*	if (!ft_is_sorted(*stack_a))
*	{
*		ft_lst_shift_stack(stack_a);
*	}
*/
void	ft_sort_four_or_more_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_b_all_but_three(stack_a, stack_b);
	ft_sort_three_nbrs(stack_a);
}

void	ft_push_b_all_but_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	index;

	stack_size = ft_lst_size(*stack_a);
	pushed = 0;
	index = 0;
	while ((stack_size > 6) && (index < stack_size)
		&& (pushed < stack_size / 2))
	{
		if ((*stack_a)->weight <= (stack_size / 2))
		{
			ft_do_push_b(stack_a, stack_b);
			pushed++;
		}
		else
			ft_do_rotate_a(stack_a);
		index++;
	}
	while (stack_size - pushed > 3)
	{
		ft_do_push_b(stack_a, stack_b);
		pushed++;
	}
	*stack_b = ft_lst_delat_end(*stack_b);
}

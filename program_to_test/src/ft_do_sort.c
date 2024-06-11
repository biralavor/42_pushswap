/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:46:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/11 15:18:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;

	if (!ft_is_sorted(*stack_a))
	{
		if (ft_lst_size(*stack_a) == 2)
			ft_sort_two_nbrs(stack_a);
		else if (ft_lst_size(*stack_a) == 3)
			ft_sort_three_nbrs(stack_a);
		else
			ft_sort_four_or_more_nbrs(stack_a, stack_b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:46:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 11:12:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lst_size(*stack_a);
	if (!ft_is_sorted(*stack_a))
	{
		if (stack_size == 2)
			ft_sort_two_nbrs(stack_a);
		else if (stack_size == 3)
			ft_sort_a_with_three_nbrs(stack_a);
		else
			ft_sort_four_or_more_nbr(stack_a, stack_b);
	}
}

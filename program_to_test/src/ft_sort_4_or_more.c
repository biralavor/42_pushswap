/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_or_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:29 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 16:21:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_lst_printf_int_content("stack_b content:", *stack_b);
			pushed++;
			ft_printf("pushed = %d\n", pushed);
		}
		else
			ft_sort_3_nbrs(stack_a);
		index++;
		ft_printf("index = %d\n", index);
	}
	while (stack_size - pushed > 3)
	{
		ft_do_push_b(stack_a, stack_b);
		pushed++;
		ft_printf("pushed = %d\n", pushed);
	}
	// ft_sort_3_nbrs(stack_a);
}

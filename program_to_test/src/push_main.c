/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
		ft_error_msg("Not enough arguments. Please provide at leats 2 numbers");
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lts_buildstack_argv(&stack_a, argv);
	ft_lst_printf_int_content("original main:", stack_a);
	ft_lst_map_all_indexers(&stack_a);
	stack_a = ft_lst_goto_head(stack_a);
	while (stack_a->next !=NULL)
	{
		ft_printf("stack_a pos[%d] main = %d and weight = %d\n", stack_a->pos, stack_a->nbr, stack_a->weight);
		stack_a = stack_a->next;
		if (stack_a->next ==NULL)
			ft_printf("stack_a pos[%d] main = %d and weight = %d\n", stack_a->pos, stack_a->nbr, stack_a->weight);
	}
	ft_do_sort(&stack_a, &stack_b);
	ft_lst_printf_int_content("updated main content:", stack_a);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	return (0);
}

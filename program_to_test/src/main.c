/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 13:09:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		ft_error_msg("1.Not enough arguments.");
	if (argc == 2)
	{
		if (ft_argv_validation(argv) == true)
			return (EXIT_SUCCESS);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lts_buildstack_argv(&stack_a, argv);
	ft_lst_map_all_indexers(&stack_a);
	ft_lst_printf_data_content("original list", stack_a);
	ft_do_sort(&stack_a, &stack_b);
	ft_lst_printf_data_content("stack_a", stack_a);
	ft_lst_printf_data_content("stack_b", stack_b);
	ft_lstclear_single_ptr(stack_a);
	return (0);
}

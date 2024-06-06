/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/06 15:15:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
	{
		ft_error_msg("Not enough arguments. Please provide at leats 2 numbers");
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lts_buildstack_argv(&stack_a, argv);
	ft_lst_printf_int_content("testing main list content:", stack_a);
	ft_printf("testing main list size: %d\n", ft_lstsize_int((t_list *)stack_a));
	if (!ft_is_sorted(stack_a))
	{
		if (ft_lstsize_int((t_list *)stack_a) == 2)
			ft_sort_2_nbrs(&stack_a);
		if (ft_lstsize_int((t_list *)stack_a) == 3)
			ft_sort_3_nbrs(&stack_a);
		ft_lst_printf_int_content("updated main list content:", stack_a);
	}
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/08 14:51:33 by umeneses         ###   ########.fr       */
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
	ft_lst_printf_int_content("testing main content:", stack_a);
	ft_printf("testing main size: %d\n", ft_lst_size(stack_a));
	ft_do_sort(&stack_a, &stack_b);
	ft_lst_printf_int_content("updated main content:", stack_a);
	ft_printf("stack_a pos na main = %d\n", stack_a->pos);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	return (0);
}

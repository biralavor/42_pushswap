/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/04 10:49:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 2)
	{
		ft_error_msg("Not enough arguments. Please provide at leats 2 numbers");
	}
	stack = NULL;
	stack = ft_lts_buildstack_argv(stack, argv);
	ft_lst_printf_int_content("testing main stack content:", stack);
	ft_printf("testing main stack size: %d\n", ft_lstsize_int((t_list *)stack));
	ft_lstclear_single_ptr(stack);
	return (0);
}

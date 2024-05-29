/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/29 14:37:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		userinput;
	int		index;
	t_stack	*stack;

	if (argc <= 2)
	{
		ft_error_msg("Not enough arguments. Please provide at leats 3 numbers");
	}
	stack = NULL;
	index = 0;
	while (argv[++index] != NULL)
	{
		userinput = ft_atoi(argv[index]);
		stack = ft_lst_addto_end(stack, ft_lst_init( userinput));
	}
	ft_printf("list size = %d\n", ft_lstsize_int((t_list *)stack));
	ft_lst_printf_int_content("stack is:", stack);
	ft_lstclear_single_ptr(stack);
	return (0);
}

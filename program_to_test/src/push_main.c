/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/28 18:40:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int		top;
	int		second;
	int		bottom;
	t_stack	*stack;

	top = 11;
	second = 22;
	bottom = 99;
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	ft_printf("list size = %d\n", ft_lstsize_int((t_list *)stack));
	ft_lst_printf_int_content("stack is:", stack);
	ft_lstclear_single_ptr(stack);
	return (0);
}

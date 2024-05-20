/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 15:54:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	int top = 11;
	int second = 22;
	int	third = 33;
	int	fourth = 44;
	int bottom = 99;
	t_stack	*stack;
	t_stack	*temp;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		ft_error_msg("Memory allocation failed\n");
	stack->next = NULL;
	stack = ft_lstend_int(stack, top);
	stack = ft_lstend_int(stack, second);
	stack = ft_lstend_int(stack, third);
	stack = ft_lstend_int(stack, fourth);
	stack = ft_lstend_int(stack, bottom);
	temp = stack;
	ft_printf("list size = %d\n", ft_lstsize_int((t_list *)temp));
	ft_printf("The content is: %d\n", temp->nbr);
	while (temp->next != NULL)
	{
		temp = temp->next;
		ft_printf("The content is: %d\n", temp->nbr);
	}
	return (0);
}

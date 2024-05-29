/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/29 15:43:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_init(int value)
{
	t_stack	*new_node;

	if (!value)
		ft_error_msg("Invalid value at lst_init()\n");
	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_lts_buildstack_argv(t_stack *stack, char **argv)
{
	int	userinput;
	int	index;

	index = 0;
	while (argv[++index] != NULL)
	{
		if (!ft_isdigit(*argv[index]))
			ft_error_msg("User's input must be numbers only\n");
		userinput = ft_atoi(argv[index]);
		stack = ft_lst_addto_end(stack, ft_lst_init(userinput));
	}
	return (stack);
}

void	ft_lst_printf_int_content(char *msg, t_stack *list)
{
	t_stack	*temp;

	temp = list;
	ft_printf("%s %d\n", msg, temp->nbr);
	while (temp->next != NULL)
	{
		temp = temp->next;
		ft_printf("%s %d\n", msg, temp->nbr);
	}
}

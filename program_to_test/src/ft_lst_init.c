/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/14 17:56:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (size);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*ft_lst_init(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_lts_buildstack_argv(t_stack **stack, char **argv)
{
	int	userinput;
	int	index;

	index = 0;
	if (!ft_argv_validation(argv))
		return (NULL);
	while (argv[++index] != NULL)
	{
		userinput = ft_atoi(argv[index]);
		*stack = ft_lst_addto_end(stack, ft_lst_init(userinput));
	}
	return (*stack);
}

void	ft_lst_printf_int_content(char *msg, t_stack *list)
{
	t_stack	*temp;

	list = ft_lst_goto_head(list);
	temp = list;
	while (temp)
	{
		ft_printf("%s\tnbr[%d]\tpos[%d]\t",msg, temp->nbr, temp->pos);
		ft_printf("weight[%d]\ttarget[%d]\t", temp->weight, temp->target);
		ft_printf("cost_a[%d]\tcost_b[%d]\n", temp->cost_a, temp->cost_b);
		temp = temp->next;
	}
}

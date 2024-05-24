/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/24 17:32:43 by umeneses         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/01 12:46:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->nbr > temp->next->nbr)
			return (false);
		temp = temp->next;
	}
	return (true);
}

t_stack	*ft_sort_two_nbrs(t_stack **list)
{
	if ((*list)->nbr > (*list)->next->nbr)
		ft_do_swap_a(list);
	return (*list);
}

t_stack	*ft_sort_a_with_three_nbrs(t_stack **stack_a)
{
	int	highest_pos;

	*stack_a = ft_lst_goto_head(*stack_a);
	if (ft_is_sorted(*stack_a))
		return (*stack_a);
	highest_pos = ft_lst_map_highest_pos(*stack_a);
	if ((*stack_a)->final_pos == highest_pos)
		ft_do_rotate_a(stack_a);
	else if ((*stack_a)->next->final_pos == highest_pos)
		ft_do_reverse_rotate_a(stack_a);
	if ((*stack_a)->final_pos > (*stack_a)->next->final_pos)
		ft_do_swap_a(stack_a);
	return (*stack_a);
}

int	ft_lst_map_highest_pos(t_stack *list)
{
	int		highest_pos;
	t_stack	*temp;

	temp = ft_lst_goto_head(list);
	highest_pos = temp->final_pos;
	while (temp)
	{
		if (temp->final_pos > highest_pos)
			highest_pos = temp->final_pos;
		temp = temp->next;
	}
	return (highest_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 16:10:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *list)
{
	t_stack	*temp;

	while (list->next != NULL)
	{
		temp = list->next;
		if (list->nbr > temp->nbr)
			return (false);
		list = list->next;
	}
	ft_lst_goto_head(list);
	ft_printf(">>>>>>>>>>>>> list is sorted!\n");
	return (true);
}

t_stack	*ft_sort_two_nbrs(t_stack **list)
{
	if ((*list)->nbr > (*list)->next->nbr)
		ft_do_swap_a(list);
	return (*list);
}

t_stack	*ft_sort_three_nbrs(t_stack **list)
{
	int	highest_pos;

	*list = ft_lst_goto_head(*list);
	if (ft_is_sorted(*list))
		return (*list);
	highest_pos = ft_lst_map_highest_pos(*list);
	if ((*list)->final_pos == highest_pos)
		ft_do_rotate_a(list);
	else if ((*list)->next->final_pos == highest_pos)
		ft_do_reverse_rotate_a(list);
	if ((*list)->final_pos > (*list)->next->final_pos)
		ft_do_swap_a(list);
	return (*list);
}

int	ft_lst_map_highest_pos(t_stack *list)
{
	int		highest_pos;
	t_stack	*temp;

	temp = list;
	temp = ft_lst_goto_head(temp);
	highest_pos = list->final_pos;
	while (temp)
	{
		if (temp->final_pos > highest_pos)
			highest_pos = temp->final_pos;
		temp = temp->next;
	}
	return (highest_pos);
}

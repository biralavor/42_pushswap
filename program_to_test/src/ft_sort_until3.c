/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/05 11:40:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *list)
{
	t_stack	*tmp;

	while (list->next != NULL)
	{
		tmp = list->next;
		if (list->nbr > tmp->nbr)
			return (false);
		list = list->next;
	}
	ft_lst_goto_head(list);
	ft_printf(">>>>>>>>>>>>> list is sorted!\n");
	return (true);
}

t_stack	*ft_sort_2_nbrs(t_stack **list)
{
	if ((*list)->nbr > (*list)->next->nbr)
		ft_do_swap_a(list);
	return (*list);
}

t_stack	*ft_sort_3_nbrs(t_stack **list)
{
	if (((*list)->nbr < (*list)->next->nbr)
		&& ((*list)->nbr > (*list)->next->next->nbr))
	{

		ft_do_reverse_rotate_a(list);
	}
	return (*list);
}

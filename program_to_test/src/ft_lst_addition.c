/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_adds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/23 14:26:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_addto_end(t_stack *list, t_stack *new)
{
	t_stack	*temp;

	if (!list)
	{
		list = new;
		return (list);
	}
	if (!new)
		return (list);
	temp = ft_lst_goto_end(list);
	temp->next = new;
	new->prev = temp;
	return (list);
}

t_stack	*ft_lst_addto_begin(t_stack *list, t_stack *new)
{
	if (!list)
	{
		list = new;
		return (list);
	}
	if (!new)
		return (list);
	new->next = list;
	return (new);
}

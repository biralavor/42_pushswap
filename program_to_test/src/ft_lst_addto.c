/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/05 18:50:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_addto_end(t_stack **list, t_stack *new)
{
	t_stack	**temp;

	temp = NULL;
	if (!*list)
	{
		*list = new;
		return (*list);
	}
	if (!new)
		return (*list);
	*temp = ft_lst_goto_end(*list);
	(*temp)->next = new;
	new->prev = (*temp);
	return (*list);
}

t_stack	*ft_lst_addto_begin(t_stack **list, t_stack *new)
{
	if (!*list)
	{
		*list = new;
		return (*list);
	}
	if (!new)
		return (*list);
	new->next = *list;
	(*list)->prev = new;
	new->prev = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_goto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 15:01:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_goto_end(t_stack *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_stack	*ft_lst_goto_before_end(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list && list->next && (list->next->next != NULL))
		list = list->next;
	return (list);
}

t_stack	*ft_lst_goto_head(t_stack *list)
{
	if (NULL == list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	if (list->prev == NULL)
		return (list);
	return (list);
}

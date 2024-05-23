/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_goto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/23 17:21:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_goto_end(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list && (list->next != NULL))
		list = list->next;
	return (list);
}

t_stack	*ft_lst_goto_before_end(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list && (list->next->next != NULL))
		list = list->next;
	return (list);
}
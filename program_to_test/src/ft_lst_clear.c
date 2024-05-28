/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:10:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/28 18:16:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_double_ptr(t_stack **list)
{
	t_stack	*temp;

	if (!list || (*list) == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

void	ft_lstclear_single_ptr(t_stack *list)
{
	t_stack	*temp;

	if (!list)
		return ;
	temp = NULL;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
	return ;
}

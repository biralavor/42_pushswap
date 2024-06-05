/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_deletes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/05 14:52:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_delat_begin(t_stack *list)
{
	t_stack	*temp;

	if (!list || list->next == NULL)
	{
		free(list);
		return (NULL);
	}
	temp = list->next;
	ft_lst_goto_head(list);
	free(list);
	return (temp);
}

t_stack	*ft_lst_delat_end(t_stack *list)
{
	t_stack	*second_last_node;

	second_last_node = NULL;
	if (!list || !list->next)
	{
		free(list);
		return (NULL);
	}
	second_last_node = ft_lst_goto_before_end(list);
	free(second_last_node->next);
	second_last_node->next = NULL;
	return (list);
}

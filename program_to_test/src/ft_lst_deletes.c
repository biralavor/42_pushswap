/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_deletes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:49:58 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/23 16:58:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_delat_begin(t_stack *list)
{
	t_stack	*temp;

	if (!list)
		return (NULL);
	temp = list->next;
	free(list);
	return (temp);
}

t_stack	*ft_lst_delat_end(t_stack *list)
{
	t_stack	*temp;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	if (temp)
	{
		temp->next = NULL;
		free(temp);
		// free(temp->next);
	}
	return (list);
}
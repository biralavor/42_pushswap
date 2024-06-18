/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:41:22 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/18 13:53:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_all_indexers(t_stack **stack)
{
	int	stack_size;

	stack_size = ft_lst_size(*stack);
	ft_lst_map_actual_position(stack);
	ft_lst_map_final_pos(stack, stack_size);
}

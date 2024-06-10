/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_indexers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_map_all_indexers(t_stack **stack)
{
	int	stack_size;

	stack_size = ft_lst_size(*stack);
	ft_lst_map_position(stack);
	ft_lst_map_weight(stack, stack_size);
}

void	ft_lst_map_position(t_stack **stack)
{
	int	pos;

	pos = 0;
	while ((*stack)->next != NULL)
	{
		pos++;
		(*stack)->pos = pos;
		(*stack) = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			pos++;
			(*stack)->pos = pos;
		}
	}
	*stack = ft_lst_goto_head(*stack);
}

void	ft_lst_map_weight(t_stack **stack, int stack_size)
{
	int		weight;
	t_stack	*target;
	t_stack	*highest;
	
	while (--stack_size > 0)
	{
		target = *stack;
		weight = INT_MIN;
		highest = NULL;
		while (target)
		{
			if (target->nbr == INT_MIN && target->weight == 0)
				target->weight = 1;
			if (target->nbr > weight && target->weight == 0)
			{
				weight = target->nbr;
				highest = target;
				target = *stack;
			}
			else
				target = target->next;
		}
		if (highest != NULL)
			highest->weight = stack_size;
	}
}


// void	ft_lst_map_weight(t_stack **stack)
// {
// 	int		weight;
// 	t_stack	*target;
// 	t_stack	*compare_node;
	
// 	target = *stack;
// 	weight = 1;
// 	while (target != NULL && target->next != NULL)
// 	{
// 		compare_node = target->next;
// 		while (compare_node != NULL)
// 		{
// 			if (target->nbr > compare_node->nbr)
// 				weight++;
// 			compare_node = compare_node->next;
// 		}
// 		target->weight = weight;
// 		target = target->next;
// 	}
// }

// void	ft_lst_map_weight_by_argv(t_stack **stack, char **argv)
// {
// 	int		weight;
// 	int		pos;
// 	char	**argv_splited;
// 	t_stack	*temp;

// 	weight = 0;
// 	pos = 0;
// 	weight = 0;
// 	temp = *stack;
// 	argv_splited = ft_split(*argv, ' ');
// 	while ((argv_splited[pos] != NULL) && (temp->next != NULL))
// 	{
// 		if (ft_atoi(argv_splited[pos]) > ft_atoi(argv_splited[pos + 1]))
// 			temp->weight = weight++;
//		temp = temp->next;
// 	}
// }

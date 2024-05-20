/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 10:39:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(void)
{
	int		result;
	int		add_one;
	int		add_two;
	int		*add_one_ptr;
	int		*add_two_ptr;
	int		*toprint = NULL;
	t_list	*new_node;

	add_one = 42;
	add_two = 21;
	add_one_ptr = &add_one;
	add_two_ptr = &add_two;
	new_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_node->content = add_one_ptr;
	new_node->next = NULL;
	ft_lstend_void(new_node, add_two_ptr);
	t_list	*temp_node;
	temp_node = new_node;
	while (temp_node != NULL)
	{
		toprint = temp_node->content;
		ft_printf("The content is: %d\n", *toprint);
		temp_node = temp_node->next;
	}
	ft_printf("///////////////\n");
	ft_printf("\033[0;35m");
	ft_printf("this is the push swap main running\n");
	result = push_add(5, 3);
	ft_printf("Operation: psuh_add(5, 3)\n");
	ft_printf("The sum is: %d\n", result);
	ft_printf("///////////////\n");
	result = push_subtract(5, 3);
	ft_printf("Operation: push_subtract(5, 3)\n");
    ft_printf("The difference is: %d\n", result);
	return (0);
}

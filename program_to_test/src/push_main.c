/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/13 14:50:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	ft_printf("\033[0;35m");
	ft_printf("this is the push swap main running\n");
	int result = push_add(5, 3);
	ft_printf("Operation: psuh_add(5, 3)\n");
	ft_printf("The sum is: %d\n", result);
	ft_printf("///////////////\n");
	result = push_subtract(5, 3);
	ft_printf("Operation: push_subtract(5, 3)\n");
    ft_printf("The difference is: %d\n", result);
	return (0);
}

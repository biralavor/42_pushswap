/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/09 19:18:47 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add(int a, int b)
{
	return (a + b);
}

int subtract(int a, int b)
{
	return (a - b);
}

int main(void)
{
	ft_printf("this is the push swap main running\n");
	int result = add(5, 3);
	ft_printf("Operation: add(5, 3)\n");
	ft_printf("The sum is: %d\n", result);
	ft_printf("\\\\\\\\\\\\\\\\n");
	result = subtract(5, 3);
	ft_printf("Operation: subtract(5, 3)\n");
    printf("The difference is: %d\n", result);
	return (0);
}

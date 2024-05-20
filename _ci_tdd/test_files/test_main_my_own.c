/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_my_own.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/13 16:00:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "../../program_to_test/src/push_functions.c"

void	test_pushadd_5plus4()
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 9;

	// ACT
	actual_result = push_add(5, 4);

	// ASSERT
	if (expected_result != actual_result)
	{
		ft_error_msg("Test failed: test_pushadd_5plus4\n");
	}
}

void	test_pushsubtract_5minus3()
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 2;

	// ACT
	actual_result = push_subtract(5, 3);

	// ASSERT
	if (expected_result != actual_result)
	{
		ft_error_msg("Test failed: test_pushsubtract_5minus3\n");
	}
}

int main(void)
{
	int	index;

	index = 0;
	ft_printf("\033[0;36m");
	ft_printf("Runing test [%d] test_pushadd_5plus4\n", ++index);
	test_pushadd_5plus4();
	ft_printf("Runing test [%d] test_pushsubtract_5minus3\n", ++index);
	test_pushsubtract_5minus3();
	ft_printf("All tests passed\n");
	return (0);
}
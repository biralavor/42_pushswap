/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/13 16:10:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/push_functions.c"

MU_TEST(test_pushadd_5plus4)
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 9;

	// ACT
	actual_result = push_add(5, 4);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

void test_pushsubtract_5minus3()
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 2;

	// ACT
	actual_result = push_subtract(5, 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(first_tests)
{
	MU_RUN_TEST(test_pushadd_5plus4);
	MU_RUN_TEST(test_pushsubtract_5minus3);
}

int main(void)
{
	MU_RUN_SUITE(first_tests);
	MU_REPORT();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/10 17:30:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../../program_to_test/src/push_main.c"

MU_TEST(test_pushadd_5plus3)
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 8;

	// ACT
	actual_result = push_add(5, 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_pushsubtract_5minus3)
{
	// ARRANGE
	int	actual_result;
	int	expected_result = 2;

	// ACT
	actual_result = push_subtract(5, 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(first_tests_suite)
{
	MU_RUN_TEST(test_pushadd_5plus3);
	MU_RUN_TEST(test_pushsubtract_5minus3);
}

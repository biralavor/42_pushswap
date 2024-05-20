/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 12:36:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/push_functions.c"

MU_TEST(test_swap_a)
{
	// ARRANGE
	int top = 5;
	int bottom = 11;
	int actual_result;
	int expected_result;
	t_stack_a	*stack_a;

	stack_a = (t_stack_a *)ft_calloc(1, sizeof(t_stack_a));
	stack_a->next = NULL;
	stack_a->prev = NULL;
	stack_a->nbr = top;
	expected_result = bottom;

	// ACT
	stack_a = ft_lstend_int(stack_a, top);
	stack_a = ft_lstend_int(stack_a, bottom);
	swap_a(&stack_a);
	actual_result = stack_a->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

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
	MU_RUN_TEST(test_swap_a);
}

int main(void)
{
	MU_RUN_SUITE(first_tests);
	MU_REPORT();
	return (0);
}

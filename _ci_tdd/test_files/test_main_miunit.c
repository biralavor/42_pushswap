/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 13:10:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/push_functions.c"

MU_TEST(test_ft_swap_ab)
{
	// ARRNAGE
	int top_a = 5;
	int	middle_a = 21;
	int bottom_a = 11;
	int top_b = 99;
	int middle_b = 88;
	int bottom_b = 77;
	int actual_result_a;
	int actual_result_b;
	int expected_result_a;
	int expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack_a->next = NULL;
	stack_b->next = NULL;
	stack_a->prev = NULL;
	stack_b->prev = NULL;
	// stack_a->nbr = top_a;
	// stack_b->nbr = top_b;
	expected_result_a = bottom_a;
	expected_result_b = bottom_b;

	// ACT
	stack_a = ft_lstend_int(stack_a, top_a);
	stack_a = ft_lstend_int(stack_a, middle_a);
	stack_a = ft_lstend_int(stack_a, bottom_a);
	stack_b = ft_lstend_int(stack_b, top_b);
	stack_b = ft_lstend_int(stack_b, middle_b);
	stack_b = ft_lstend_int(stack_b, bottom_b);
	ft_swap_ab(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
}

MU_TEST(test_ft_swap)
{
	// ARRANGE
	int top = 5;
	int middle = 21;
	int bottom = 11;
	int actual_result;
	int expected_result;
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->next = NULL;
	stack->prev = NULL;
	// stack->nbr = top;
	expected_result = bottom;

	// ACT
	stack = ft_lstend_int(stack, top);
	stack = ft_lstend_int(stack, middle);
	stack = ft_lstend_int(stack, bottom);
	ft_swap(&stack);
	actual_result = stack->nbr;

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
	MU_RUN_TEST(test_ft_swap);
	MU_RUN_TEST(test_ft_swap_ab);
}

int main(void)
{
	MU_RUN_SUITE(first_tests);
	MU_REPORT();
	return (0);
}

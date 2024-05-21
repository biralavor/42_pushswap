/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/21 15:45:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/push_functions.c"


MU_TEST(test_ft_swap_ab)
{
	// ARRANGE
	int	top_a = 11;
	int	second_a = 22;
	int	third_a = 33;
	int	bottom_a = 44;
	int	top_b = 99;
	int	second_b = 88;
	int	third_b = 77;
	int	bottom_b = 55;
	int	actual_result_a;
	int	actual_result_b;
	int	expected_result_a;
	int	expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack_a->next = NULL;
	stack_b->next = NULL;
	stack_a->prev = NULL;
	stack_b->prev = NULL;
	expected_result_a = second_a;
	expected_result_b = second_b;

	// ACT
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lstend_int(stack_a, second_a);
	stack_a = ft_lstend_int(stack_a, third_a);
	stack_a = ft_lstend_int(stack_a, bottom_a);
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lstend_int(stack_b, second_b);
	stack_b = ft_lstend_int(stack_b, third_b);
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
	int	top = 11;
	int	second = 22;
	int	third = 33;
	int	bottom = 99;
	int	actual_result;
	int	expected_result;
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->next = NULL;
	stack->prev = NULL;
	expected_result = second;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lstend_int(stack, second);
	stack = ft_lstend_int(stack, third);
	stack = ft_lstend_int(stack, bottom);
	ft_swap(&stack);
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_lstend_int)
{
	// ARRANGE
	int expected_result = 22;
	int actual_result;
	t_stack *stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->prev = NULL;
	stack->next = NULL;

	// ACT
	stack = ft_lstend_int(stack, expected_result);
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_lst_init)
{
	// ARRANGE
	int	expected_result = 11;
	int	actual_result;
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->next = NULL;
	stack->prev = NULL;

	// ACT
	stack = ft_lst_init(expected_result);
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

MU_TEST_SUITE(linked_list_tests)
{
	MU_RUN_TEST(test_lst_init);
	MU_RUN_TEST(test_lstend_int);
}

MU_TEST_SUITE(swap_tests)
{
	MU_RUN_TEST(test_ft_swap);
	MU_RUN_TEST(test_ft_swap_ab);
}

MU_TEST_SUITE(testing_the_tester)
{
	MU_RUN_TEST(test_pushadd_5plus4);
	MU_RUN_TEST(test_pushsubtract_5minus3);
}

int main(void)
{
	MU_RUN_SUITE(testing_the_tester);
	MU_RUN_SUITE(swap_tests);
	MU_RUN_SUITE(linked_list_tests);
	MU_REPORT();
	return (0);
}

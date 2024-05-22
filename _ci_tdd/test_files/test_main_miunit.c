/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/22 11:34:39 by umeneses         ###   ########.fr       */
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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
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
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(third));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));

	ft_swap(&stack);
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_lst_addto_end)
{
	// ARRANGE
	int top = 11;
	int	middle = 22;
	int bottom = 33;
	int expected_result;
	int actual_result;
	t_stack *stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->prev = NULL;
	stack->next = NULL;
	expected_result = bottom;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = stack->next->next->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_lst_goto_end)
{
	// ARRANGE
	int top = 11;
	int bottom = 22;
	int expected_result;
	int actual_result;
	t_stack *stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->prev = NULL;
	stack->next = NULL;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_end(stack)->nbr;
	expected_result = bottom;

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

MU_TEST_SUITE(linked_list_tests)
{
	MU_RUN_TEST(test_lst_init);
	MU_RUN_TEST(test_lst_goto_end);
	MU_RUN_TEST(test_lst_addto_end);
}

MU_TEST_SUITE(swap_tests)
{
	MU_RUN_TEST(test_ft_swap);
	MU_RUN_TEST(test_ft_swap_ab);
}

int main(void)
{
	MU_RUN_SUITE(linked_list_tests);
	MU_RUN_SUITE(swap_tests);
	MU_REPORT();
	return (0);
}

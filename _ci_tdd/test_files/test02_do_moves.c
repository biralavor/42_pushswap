/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02_do_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:48:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"


MU_TEST(test_ft_reverse_rotate_ab)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		top_b = 999;
	int		second_b = 888;
	int		third_b = 777;
	int		bottom_b = 666;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	int		actual_size_a;
	int		expected_size_a;
	int		actual_size_b;
	int		expected_size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ACT
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lst_size(stack_a);
	expected_size_b = ft_lst_size(stack_b);
	expected_result_a = bottom_a;
	expected_result_b = bottom_b;
	ft_reverse_rotate_ab(&stack_a, &stack_b);
	actual_size_a = ft_lst_size(stack_a);
	actual_size_b = ft_lst_size(stack_b);
	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
	actual_result_b = ft_lst_goto_head(stack_b)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	mu_assert_int_eq(expected_size_b, actual_size_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_reverse_rotate)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		actual_result_a;
	int		expected_result_a;
	int		actual_size_a;
	int		expected_size_a;
	t_stack	*stack_a;

	// ACT
	stack_a = NULL;
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	expected_result_a = bottom_a;
	expected_size_a = ft_lst_size(stack_a);
	ft_reverse_rotate(&stack_a);
	actual_size_a = ft_lst_size(stack_a);
	actual_result_a = ft_lst_goto_head(stack_a)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	ft_lstclear_single_ptr(stack_a);
}

MU_TEST(test_ft_rotate_ab)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		top_b = 999;
	int		second_b = 888;
	int		third_b = 777;
	int		bottom_b = 666;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	int		actual_size_a;
	int		actual_size_b;
	int		expected_size_a;
	int		expected_size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
	expected_result_a = second_a;
	expected_result_b = second_b;
	expected_size_a = ft_lst_size(stack_a);
	expected_size_b = ft_lst_size(stack_b);
	ft_rotate_ab(&stack_a, &stack_b);
	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
	actual_size_a = ft_lst_size(stack_a);
	actual_size_b = ft_lst_size(stack_b);	

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	mu_assert_int_eq(expected_size_b, actual_size_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_rotate)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		actual_result_a;
	int		expected_result_a;
	int		expected_size;
	int		actual_size;
	t_stack	*stack_a;

	// ACT
	stack_a = NULL;
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	expected_result_a = second_a;
	expected_size = ft_lst_size(stack_a);
	ft_rotate(&stack_a);
	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
}

MU_TEST(test_ft_push_b)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		top_b = 999;
	int		second_b = 888;
	int		third_b = 777;
	int		bottom_b = 666;
	int		actual_top_a;
	int		actual_top_b;
	int		expected_top_a;
	int		expected_top_b;
	int		actual_bottom_a;
	int		actual_bottom_b;
	int		expected_bottom_a;
	int		expected_bottom_b;
	int		actual_size_a;
	int		actual_size_b;
	int		expected_size_a;
	int		expected_size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
	expected_top_a = second_a;
	expected_bottom_a = bottom_a;
	expected_top_b = top_a;
	expected_bottom_b = bottom_b;
	expected_size_a = ft_lst_size(stack_a) - 1;
	expected_size_b = ft_lst_size(stack_b) + 1;
	ft_push_b(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_top_b = ft_lst_goto_head(stack_b)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_bottom_b = ft_lst_goto_end(stack_b)->nbr;
	actual_size_a = ft_lst_size(stack_a);
	actual_size_b = ft_lst_size(stack_b);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_top_b, actual_top_b);
	mu_assert_int_eq(expected_bottom_b, actual_bottom_b);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	mu_assert_int_eq(expected_size_b, actual_size_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_push_a)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		top_b = 999;
	int		second_b = 888;
	int		third_b = 777;
	int		bottom_b = 666;
	int		actual_top_a;
	int		actual_top_b;
	int		expected_top_a;
	int		expected_top_b;
	int		actual_bottom_a;
	int		actual_bottom_b;
	int		expected_bottom_a;
	int		expected_bottom_b;
	int		actual_size_a;
	int		actual_size_b;
	int		expected_size_a;
	int		expected_size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lst_size(stack_a) + 1;
	expected_size_b = ft_lst_size(stack_b) - 1;
	expected_top_a = top_b;
	expected_bottom_a = bottom_a;
	expected_top_b = second_b;
	expected_bottom_b = bottom_b;
	ft_push_a(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_top_b = ft_lst_goto_head(stack_b)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_bottom_b = ft_lst_goto_end(stack_b)->nbr;
	actual_size_a = ft_lst_size(stack_a);
	actual_size_b = ft_lst_size(stack_b);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_top_b, actual_top_b);
	mu_assert_int_eq(expected_bottom_b, actual_bottom_b);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	mu_assert_int_eq(expected_size_b, actual_size_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_swap_ab)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		fourth_a = 44;
	int		bottom_a = 55;
	int		top_b = 999;
	int		second_b = 888;
	int		third_b = 777;
	int		fourth_b = 666;
	int		bottom_b = 555;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	int		actual_size_a;
	int		actual_size_b;
	int		expected_size_a;
	int		expected_size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(top_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(fourth_a));
	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(top_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(fourth_b));
	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lst_size(stack_a);
	expected_size_b = ft_lst_size(stack_b);
	expected_result_a = second_a;
	expected_result_b = second_b;

	ft_swap_ab(&stack_a, &stack_b);
	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
	actual_size_a = ft_lst_size(stack_a);
	actual_size_b = ft_lst_size(stack_b);

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
	mu_assert_int_eq(expected_size_a, actual_size_a);
	mu_assert_int_eq(expected_size_b, actual_size_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_swap)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		fourth = 44;
	int		bottom = 99;
	int		expected_top;
	int		expected_bottom;
	int		actual_top;
	int		actual_bottom;
	int		expected_size;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
	stack = ft_lst_addto_end(&stack, ft_lst_init(fourth));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	expected_top = second;
	expected_bottom = bottom;
	expected_size = ft_lst_size(stack);
	ft_swap(&stack);
	actual_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lst_size(stack);
	actual_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
	ft_lstclear_single_ptr(stack);
}

MU_TEST_SUITE(swap_tests)
{
	MU_RUN_TEST(test_ft_swap);
	MU_RUN_TEST(test_ft_swap_ab);
}

MU_TEST_SUITE(push_tests)
{
	MU_RUN_TEST(test_ft_push_a);
	MU_RUN_TEST(test_ft_push_b);
}

MU_TEST_SUITE(rotate_tests)
{
	MU_RUN_TEST(test_ft_rotate);
	MU_RUN_TEST(test_ft_rotate_ab);
	MU_RUN_TEST(test_ft_reverse_rotate);
	MU_RUN_TEST(test_ft_reverse_rotate_ab);
}

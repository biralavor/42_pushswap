/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/23 17:28:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/ft_lst_init.c"
#include "../../program_to_test/src/ft_lst_goto.c"
#include "../../program_to_test/src/ft_lst_addition.c"
#include "../../program_to_test/src/ft_lst_deletes.c"
#include "../../program_to_test/src/ft_lst_clear.c"
#include "../../program_to_test/src/ft_swap.c"
#include "../../program_to_test/src/ft_push.c"
#include "../../program_to_test/src/ft_rotate.c"

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

	expected_result_a = bottom_a;

	// ACT
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	expected_size_a = ft_lstsize_int((t_list *)stack_a);
	ft_reverse_rotate(&stack_a);
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_result_a = stack_a->nbr;
	ft_printf("reverse rotate stack_A nbr: %d\n", stack_a->nbr);
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		ft_printf("reverse rotate stack_A nbr: %d\n", stack_a->nbr);
	}

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
	int		bottom_b = 555;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	ft_rotate_ab(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	// ft_printf("rotate stack_A nbr: %d\n", stack_a->nbr);
	// while (stack_a->next != NULL)
	// {
	// 	stack_a = stack_a->next;
	// 	ft_printf("rotate stack_A nbr: %d\n", stack_a->nbr);
	// }
	// ft_printf("rotate stack_B nbr: %d\n", stack_b->nbr);
	// while (stack_b->next != NULL)
	// {
	// 	stack_b = stack_b->next;
	// 	ft_printf("rotate stack_B nbr: %d\n", stack_b->nbr);
	// }

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
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
	t_stack	*stack_a;

	expected_result_a = second_a;

	// ACT
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	ft_rotate(&stack_a);
	actual_result_a = stack_a->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
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
	int		bottom_b = 555;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	expected_result_a = second_a;
	expected_result_b = top_a;

	// ACT
	stack_a = ft_lst_init(top_a);
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	ft_push_b(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
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
	int		bottom_b = 555;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	expected_result_a = top_b;
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
	ft_push_a(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_swap_ab)
{
	// ARRANGE
	int		top_a = 11;
	int		second_a = 22;
	int		third_a = 33;
	int		bottom_a = 44;
	int		top_b = 99;
	int		second_b = 88;
	int		third_b = 77;
	int		bottom_b = 55;
	int		actual_result_a;
	int		actual_result_b;
	int		expected_result_a;
	int		expected_result_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
}

MU_TEST(test_ft_swap)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 99;
	int		actual_result;
	int		expected_result;
	t_stack	*stack;

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
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_addto_end)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		actual_result;
	t_stack	*stack;

	expected_result = bottom;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = stack->next->next->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_delat_end)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 44;
	int		expected_result;
	int		actual_result;
	int		expected_size;
	int		actual_size;
	t_stack	*stack;

	expected_result = third;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(third));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	expected_size = ft_lstsize_int((t_list *)stack) - 1;

	stack = ft_lst_delat_end(stack);
	actual_size = ft_lstsize_int((t_list *)stack);
	ft_printf("delat_end stack nbr: %d\n", stack->nbr);
	while (stack->next != NULL)
	{
		actual_result = stack->nbr;
		stack = stack->next;
		ft_printf("delat_end stack nbr: %d\n", stack->nbr);
	}
	ft_printf("delat_end actual_result: %d\n", actual_result);
	ft_printf("delat_end expected_result: %d\n", expected_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_delat_begin)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		actual_result;
	t_stack	*stack;

	expected_result = middle;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	stack = ft_lst_delat_begin(stack);
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_addto_begin)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		actual_result;
	t_stack	*stack;

	expected_result = bottom;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_begin(stack, ft_lst_init(bottom));
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_goto_before_end)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		actual_result;
	t_stack	*stack;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_before_end(stack)->nbr;
	expected_result = middle;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_goto_end)
{
	// ARRANGE
	int		top = 11;
	int		bottom = 22;
	int		expected_result;
	int		actual_result;
	t_stack	*stack;

	// ACT
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_end(stack)->nbr;
	expected_result = bottom;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_init)
{
	// ARRANGE
	int		expected_result = 11;
	int		actual_result;
	t_stack	*stack;

	// ACT
	stack = ft_lst_init(expected_result);
	actual_result = stack->nbr;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_lstclear_single_ptr(stack);
}

MU_TEST_SUITE(linked_list_tests)
{
	MU_RUN_TEST(test_lst_init);
	MU_RUN_TEST(test_lst_goto_end);
	MU_RUN_TEST(test_lst_goto_before_end);
	MU_RUN_TEST(test_lst_addto_end);
	MU_RUN_TEST(test_lst_addto_begin);
	MU_RUN_TEST(test_lst_delat_begin);
	MU_RUN_TEST(test_lst_delat_end);
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
}

int main(void)
{
	MU_RUN_SUITE(linked_list_tests);
	MU_RUN_SUITE(swap_tests);
	MU_RUN_SUITE(push_tests);
	MU_RUN_SUITE(rotate_tests);
	MU_REPORT();
	return (0);
}

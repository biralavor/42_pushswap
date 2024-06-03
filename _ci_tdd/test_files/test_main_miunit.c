/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/03 18:49:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/ft_argv_validation.c"
#include "../../program_to_test/src/ft_lst_init.c"
#include "../../program_to_test/src/ft_lst_goto.c"
#include "../../program_to_test/src/ft_lst_addition.c"
#include "../../program_to_test/src/ft_lst_deletes.c"
#include "../../program_to_test/src/ft_lst_clear.c"
#include "../../program_to_test/src/ft_swap.c"
#include "../../program_to_test/src/ft_push.c"
#include "../../program_to_test/src/ft_rotate.c"

// TODO: Add tests for the following functions:
// ft_argv_size
// ft_is_sign
// ft_is_space
// ft_argv_is_duplicated
// ft_argv_validation

MU_TEST(test_buildstack_argv)
{
	// ARRANGE
	t_stack *stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;

	// ACT
	stack = NULL;
	userinput = "0 1 3 5 2 4 7 6";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_strlen(userinput) / 2;
	stack = ft_lts_buildstack_argv(stack, argv_simulation);
	actual_size = ft_lstsize_int((t_list *)stack);

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
	while (expected_size >= 0)
	{
		free(argv_simulation[expected_size]);
		expected_size--;
	}
}

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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lstsize_int((t_list *)stack_a);
	expected_size_b = ft_lstsize_int((t_list *)stack_b);
	ft_reverse_rotate_ab(&stack_a, &stack_b);
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_size_b = ft_lstsize_int((t_list *)stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	expected_result_a = bottom_a;
	expected_result_b = bottom_b;

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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	expected_result_a = bottom_a;
	expected_size_a = ft_lstsize_int((t_list *)stack_a);
	ft_reverse_rotate(&stack_a);
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_result_a = stack_a->nbr;

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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	expected_result_a = second_a;
	expected_result_b = second_b;
	expected_size_a = ft_lstsize_int((t_list *)stack_a);
	expected_size_b = ft_lstsize_int((t_list *)stack_b);
	ft_rotate_ab(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_size_b = ft_lstsize_int((t_list *)stack_b);

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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	expected_result_a = second_a;
	expected_size = ft_lstsize_int((t_list *)stack_a);
	ft_rotate(&stack_a);
	actual_result_a = stack_a->nbr;
	actual_size = ft_lstsize_int((t_list *)stack_a);

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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	expected_result_a = second_a;
	expected_result_b = top_a;
	expected_size_a = ft_lstsize_int((t_list *)stack_a) - 1;
	expected_size_b = ft_lstsize_int((t_list *)stack_b) + 1;
	ft_push_b(&stack_a, &stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_size_b = ft_lstsize_int((t_list *)stack_b);

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lstsize_int((t_list *)stack_a) + 1;
	expected_size_b = ft_lstsize_int((t_list *)stack_b) - 1;
	ft_push_a(&stack_a, &stack_b);
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_size_b = ft_lstsize_int((t_list *)stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	expected_result_a = top_b;
	expected_result_b = second_b;

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
	mu_assert_int_eq(expected_result_b, actual_result_b);
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
	int		bottom_a = 44;
	int		top_b = 99;
	int		second_b = 88;
	int		third_b = 77;
	int		bottom_b = 66;
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
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(second_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(third_a));
	stack_a = ft_lst_addto_end(stack_a, ft_lst_init(bottom_a));
	stack_b = ft_lst_init(top_b);
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(second_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(third_b));
	stack_b = ft_lst_addto_end(stack_b, ft_lst_init(bottom_b));
	expected_size_a = ft_lstsize_int((t_list *)stack_a);
	expected_size_b = ft_lstsize_int((t_list *)stack_b);
	ft_swap_ab(&stack_a, &stack_b);
	actual_size_a = ft_lstsize_int((t_list *)stack_a);
	actual_size_b = ft_lstsize_int((t_list *)stack_b);
	actual_result_a = stack_a->nbr;
	actual_result_b = stack_b->nbr;
	expected_result_a = second_a;
	expected_result_b = second_b;

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
	int		bottom = 99;
	int		expected_result;
	int		actual_result;
	int		expected_size;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(third));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	expected_result = second;
	expected_size = ft_lstsize_int((t_list *)stack);

	ft_swap(&stack);
	actual_result = stack->nbr;
	actual_size = ft_lstsize_int((t_list *)stack);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
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

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(third));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	expected_size = ft_lstsize_int((t_list *)stack) - 1;
	expected_result = third;

	stack = ft_lst_delat_end(stack);
	actual_size = ft_lstsize_int((t_list *)stack);
	actual_result = ft_lst_goto_end(stack)->nbr;

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
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	expected_size = ft_lstsize_int((t_list *)stack) - 1;
	expected_result = middle;
	stack = ft_lst_delat_begin(stack);
	actual_result = stack->nbr;
	actual_size = ft_lstsize_int((t_list *)stack);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lstsize_int_expec_3)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		bottom = 33;
	int		expected_size;
	int		actual_size;
	t_stack *stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(second));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
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
	int		expected_size;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = stack->next->next->nbr;
	expected_result = bottom;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_addto_begin)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	expected_result = bottom;
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_begin(stack, ft_lst_init(bottom));
	actual_result = stack->nbr;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_goto_before_end)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_before_end(stack)->nbr;
	expected_result = middle;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_goto_head)
{
	// ARRANGE
	int		top = 11;
	int		middle = 22;
	int		bottom = 33;
	int		expected_result;
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(middle));
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_head(stack)->nbr;
	expected_result = top;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_goto_end)
{
	// ARRANGE
	int		top = 11;
	int		bottom = 22;
	int		expected_result;
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(stack, ft_lst_init(bottom));
	actual_result = ft_lst_goto_end(stack)->nbr;
	expected_result = bottom;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 2;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

// MU_TEST(test_lst_init_non_nbr)
// {
// 	// ARRANGE
// 	int		char_test = 'a';
// 	int		expected_result;
// 	int		actual_result;
// 	t_stack	*stack;

// 	// ACT
// 	stack = ft_lst_init(char_test);
// 	actual_result = stack->nbr;
// 	expected_result = '\0';

// 	// ASSERT
// 	mu_assert_int_eq(expected_result, actual_result);
// 	ft_lstclear_single_ptr(stack);
// }

MU_TEST(test_lst_init_nbr)
{
	// ARRANGE
	int		top = 11;
	int		expected_result;
	int		expected_size;
	int		actual_result;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = ft_lst_init(top);
	actual_result = stack->nbr;
	expected_result = top;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 1;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST_SUITE(buildstack_argv_tests)
{
	MU_RUN_TEST(test_buildstack_argv);
}

MU_TEST_SUITE(linked_list_tests)
{
	MU_RUN_TEST(test_lst_init_nbr);
	// MU_RUN_TEST(test_lst_init_non_nbr);
	MU_RUN_TEST(test_lst_goto_end);
	MU_RUN_TEST(test_lst_goto_head);
	MU_RUN_TEST(test_lst_goto_before_end);
	MU_RUN_TEST(test_lst_addto_end);
	MU_RUN_TEST(test_lst_addto_begin);
	MU_RUN_TEST(test_lstsize_int_expec_3);
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
	MU_RUN_TEST(test_ft_reverse_rotate_ab);
}

int main(void)
{
	MU_RUN_SUITE(linked_list_tests);
	MU_RUN_SUITE(swap_tests);
	MU_RUN_SUITE(push_tests);
	MU_RUN_SUITE(rotate_tests);
	MU_RUN_SUITE(buildstack_argv_tests);
	MU_REPORT();
	return (0);
}

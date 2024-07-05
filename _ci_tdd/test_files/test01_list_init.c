/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:48:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"


MU_TEST(test_lst_delat_end)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 44;
	int		expected_top;
	int		expected_bottom;
	int		expected_size;
	int		actual_top;
	int		actual_bottom;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	stack = ft_lst_goto_head(stack);
	expected_size = ft_lst_size(stack) - 1;
	expected_top = top;
	expected_bottom = third;
	stack = ft_lst_delat_end(stack);
	actual_bottom = ft_lst_goto_end(stack)->nbr;
	actual_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lst_size(stack);

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_delat_begin)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 44;
	int		expected_top;
	int		expected_bottom;
	int		expected_size;
	int		actual_top;
	int		actual_bottom;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	stack = ft_lst_goto_head(stack);
	expected_size = ft_lst_size(stack) - 1;
	expected_top = second;
	expected_bottom = bottom;
	stack = ft_lst_delat_begin(stack);
	actual_bottom = ft_lst_goto_end(stack)->nbr;
	actual_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lst_size(stack);

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_gotoend_head_and_beforeend)
{
	// ARRANGE
	int			top = 11;
	int			second = 22;
	int			third = 33;
	int			bottom = 44;
	int			expected_top;
	int			expected_bottom;
	int			expected_before_end;
	int			actual_top;
	int			actual_bottom;
	int			actual_before_end;
	int			expected_size;
	int			actual_size;
	int			actual_top_again;
	t_stack		*actual_ptr;
	t_stack		*expected_ptr;
	t_stack		*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	expected_top = top;
	expected_before_end = third;
	expected_bottom = bottom;
	expected_size = 4;
	expected_ptr = stack;
	
	actual_bottom = ft_lst_goto_end(stack)->nbr;
	actual_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lst_size(stack);
	actual_before_end = ft_lst_goto_before_end(stack)->nbr;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	actual_top_again = ft_lst_goto_head(stack)->nbr;
	actual_ptr = ft_lst_goto_head(stack);

	// ASSERT
	mu_assert_mem_eq(&expected_ptr, &actual_ptr, sizeof(t_stack *));
	mu_assert_int_eq(expected_top, actual_top_again);
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_before_end, actual_before_end);
	mu_assert_int_eq(expected_bottom, actual_bottom);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_addto_end)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 44;
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
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	expected_top = top;
	expected_bottom = bottom;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_top = stack->nbr;
	while (stack && stack->next)
		stack = stack->next;
	actual_bottom = stack->nbr;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_size = ft_lst_size(stack);
	expected_size = 4;

	// ASSERT
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST(test_lst_addto_begin)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		third = 33;
	int		bottom = 44;
	int		expected_top;
	int		expected_bottom;
	int		expected_size;
	int		actual_top;
	int		actual_bottom;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_begin(&stack, ft_lst_init(second));
	stack = ft_lst_addto_begin(&stack, ft_lst_init(third));
	stack = ft_lst_addto_begin(&stack, ft_lst_init(bottom));
	expected_top = bottom;
	expected_bottom = top;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_top = stack->nbr;
	while (stack && stack->next)
		stack = stack->next;
	actual_bottom = stack->nbr;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_size = ft_lst_size(stack);
	expected_size = 4;

	// ASSERT
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
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
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	actual_size = ft_lst_size(stack);
	expected_size = 3;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

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
	actual_size = ft_lst_size(stack);
	if ((stack->next == NULL) && (stack->prev == NULL))
		expected_size = 1;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
}

MU_TEST_SUITE(linked_list_tests)
{
	MU_RUN_TEST(test_lst_init_nbr);
	MU_RUN_TEST(test_lstsize_int_expec_3);
	MU_RUN_TEST(test_lst_addto_begin);
	MU_RUN_TEST(test_lst_addto_end);
	MU_RUN_TEST(test_lst_gotoend_head_and_beforeend);
	MU_RUN_TEST(test_lst_delat_begin);
	MU_RUN_TEST(test_lst_delat_end);
}

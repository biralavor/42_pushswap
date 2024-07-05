/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"




MU_TEST(test_sort_3_nbrs_already_sorted)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 1 2 3";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[1]);
	expected_sorted_bottom = ft_atoi(argv_simulation[3]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_3_nbrs_highest_last)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2 1 3";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[2]);
	expected_sorted_bottom = ft_atoi(argv_simulation[3]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_3_nbrs_highest_first_v2)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 3 2 1";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[3]);
	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_3_nbrs_highest_first)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 3 1 2";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[2]);
	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_3_nbrs_highest_at_middle_v2)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 1 3 2";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[1]);
	expected_sorted_bottom = ft_atoi(argv_simulation[2]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
	stack = ft_lst_goto_head(stack);
	actual_sorted_top = (stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_3_nbrs_highest_at_middle)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2 3 1";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[3]);
	expected_sorted_bottom = ft_atoi(argv_simulation[2]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_all_indexers(&stack);
	stack = ft_sort_a_with_three_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_2_nbrs_with_zero)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 42 0";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_top = ft_atoi(argv_simulation[2]);
	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	stack = ft_sort_two_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_2_nbrs_without_zero)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2147483647 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
	expected_sorted_top = ft_atoi(argv_simulation[2]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	stack = ft_sort_two_nbrs(&stack);
	actual_size = ft_lst_size(stack);
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_buildstack_non_nbr)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		index;
	int		expected_size;
	int		actual_size;
	int		expected_argv_validation;
	int		actual_argv_validation;

	// ACT
	userinput = "./push_swap 1 3 5 2 4 7 a";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = 7;
	expected_argv_validation = false;
	actual_size = ft_minunit_array_counter(argv_simulation);
	index = expected_size;
	while (index >= 0)
	{
		if (!ft_isdigit(*argv_simulation[index]))
		{
			actual_argv_validation = false;
			break ;
		}
		index--;
	}

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_argv_validation, actual_argv_validation);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_buildstack_argv)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_sorted_bottom;
	int		actual_sorted_bottom;
	int		expected_sorted_top;
	int		actual_sorted_top;
	t_stack	*stack;

	// ACT
	stack = NULL;
	userinput = "./push_swap 1 3 5 2 4 7 6";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_sorted_bottom = ft_atoi(argv_simulation[7]);
	expected_sorted_top = ft_atoi(argv_simulation[1]);
	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lst_size(stack);
	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_inside_range_intmin_intmax_outside_int_min)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected;
	int		result;

	// ACT
	userinput = "./push_swap 1 4 3 2 -2147483649 12 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected = false;
	
	result = ft_argv_inside_range_intmin_intmax(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected, result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_inside_range_intmin_intmax_inside_int_min)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected;
	int		result;

	// ACT
	userinput = "./push_swap 1 4 3 2 -2147483648 12 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected = true;
	
	result = ft_argv_inside_range_intmin_intmax(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected, result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_inside_range_intmin_intmax_outside_int_max)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected;
	int		result;

	// ACT
	userinput = "./push_swap 1 4 3 2 2147483649 12 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected = false;
	
	result = ft_argv_inside_range_intmin_intmax(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected, result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_inside_range_intmin_intmax_inside_int_max)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected;
	int		result;

	// ACT
	userinput = "./push_swap 1 4 3 2 2147483647 12 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected = true;
	
	result = ft_argv_inside_range_intmin_intmax(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected, result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_is_duplicated_true)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected_result;
	int		actual_result;

	// ACT
	userinput = "./push_swap 1 2 3 4 5 6 7 8 2 9";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	actual_result = ft_argv_is_not_duplicated(argv_simulation);
	expected_result = false;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_is_duplicated_false)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		expected_result;
	int		actual_result;

	// ACT
	userinput = "./push_swap 1 2 3 4 5 6 7 8";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	actual_result = ft_argv_is_not_duplicated(argv_simulation);
	expected_result = true;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_argv_size)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;

	// ACT
	userinput = "./push_swap 1 2 3 4 5 6 7 8";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	actual_size = ft_argv_size(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_size, actual_size);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST_SUITE(argv_tests)
{
	MU_RUN_TEST(test_argv_size);
	MU_RUN_TEST(test_argv_is_duplicated_false);
	MU_RUN_TEST(test_argv_is_duplicated_true);
	MU_RUN_TEST(test_argv_inside_range_intmin_intmax_inside_int_min);
	MU_RUN_TEST(test_argv_inside_range_intmin_intmax_outside_int_min);
	MU_RUN_TEST(test_argv_inside_range_intmin_intmax_inside_int_max);
	MU_RUN_TEST(test_argv_inside_range_intmin_intmax_outside_int_max);
	MU_RUN_TEST(test_buildstack_argv);
	MU_RUN_TEST(test_buildstack_non_nbr);
}

MU_TEST_SUITE(sorting_2_or_3_nbrs_tests)
{
	MU_RUN_TEST(test_sort_2_nbrs_without_zero);
	MU_RUN_TEST(test_sort_2_nbrs_with_zero);
	MU_RUN_TEST(test_sort_3_nbrs_highest_at_middle);
	MU_RUN_TEST(test_sort_3_nbrs_highest_at_middle_v2);
	MU_RUN_TEST(test_sort_3_nbrs_highest_first);
	MU_RUN_TEST(test_sort_3_nbrs_highest_first_v2);
	MU_RUN_TEST(test_sort_3_nbrs_highest_last);
	MU_RUN_TEST(test_sort_3_nbrs_already_sorted);
}

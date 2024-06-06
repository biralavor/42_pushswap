/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/06 13:29:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/ft_argv_validation.c"
#include "../../program_to_test/src/ft_lst_init.c"
#include "../../program_to_test/src/ft_lst_goto.c"
#include "../../program_to_test/src/ft_lst_addto.c"
#include "../../program_to_test/src/ft_lst_deletes.c"
#include "../../program_to_test/src/ft_lst_clear.c"
#include "../../program_to_test/src/ft_swap.c"
#include "../../program_to_test/src/ft_push.c"
#include "../../program_to_test/src/ft_rotate.c"
#include "../../program_to_test/src/ft_sort_until3.c"
#include "../../program_to_test/src/ft_do_push_fts.c"
#include "../../program_to_test/src/ft_do_rev_rotate_fts.c"
#include "../../program_to_test/src/ft_do_rotate_fts.c"
#include "../../program_to_test/src/ft_do_swap_fts.c"
// #include "minunit_utils.c"
// #include "minunit_utils.h"

// TODO:
// make test for a list with three, four and five numbers
// make test for signs (- +)
// make test for non-numbers input
// make test for empty list

int		ft_minunit_array_counter(char **array);
void	ft_array_clear(char **array, int arr_size);
void	ft_array_printer(char **array, int arr_size);

// MU_TEST(test_sort_3_nbrs_highest_last)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 2 1 3";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[3]);
// 	expected_sorted_top = ft_atoi(argv_simulation[2]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	ft_lst_printf_int_content("highest_1st -previous list:", stack);
// 	ft_printf("before list size = %d\n", ft_lstsize_int((t_list *)stack));
// 	stack = ft_sort_3_nbrs(&stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;
// 	ft_lst_printf_int_content("highest_1st -  sorted list:", stack);
// 	ft_printf("after list size = %d\n", ft_lstsize_int((t_list *)stack));
// 	ft_array_printer(argv_simulation, expected_size);

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_sort_3_nbrs_highest_first)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 3 1 2";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
// 	expected_sorted_top = ft_atoi(argv_simulation[2]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	stack = ft_sort_3_nbrs(&stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_sort_3_nbrs_highest_at_middle)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 2 3 1";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[2]);
// 	expected_sorted_top = ft_atoi(argv_simulation[3]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	stack = ft_sort_3_nbrs(&stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_sort_2_nbrs_with_zero)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 42 0";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
// 	expected_sorted_top = ft_atoi(argv_simulation[2]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	stack = ft_sort_2_nbrs(&stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_sort_2_nbrs_without_zero)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 2147483647 9";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[1]);
// 	expected_sorted_top = ft_atoi(argv_simulation[2]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	stack = ft_sort_2_nbrs(&stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_buildstack_argv)
// {
// 	// ARRANGE
// 	t_stack	*stack;
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;
// 	int		expected_sorted_bottom;
// 	int		actual_sorted_bottom;
// 	int		expected_sorted_top;
// 	int		actual_sorted_top;

// 	// ACT
// 	stack = NULL;
// 	userinput = "./push_swap 1 3 5 2 4 7 6";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	expected_sorted_bottom = ft_atoi(argv_simulation[7]);
// 	expected_sorted_top = ft_atoi(argv_simulation[1]);
// 	stack = ft_lts_buildstack_argv(stack, argv_simulation);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_sorted_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_sorted_top = ft_lst_goto_head(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_sorted_bottom, actual_sorted_bottom);
// 	mu_assert_int_eq(expected_sorted_top, actual_sorted_top);
// 	ft_lstclear_single_ptr(stack);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_argv_is_duplicated_true)
// {
// 	// ARRANGE
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		expected_result;
// 	int		actual_result;

// 	// ACT
// 	userinput = "./push_swap 1 2 3 4 5 6 7 8 2 9";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	actual_result = ft_argv_is_duplicated(argv_simulation);
// 	expected_result = true;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result, actual_result);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_argv_is_duplicated_false)
// {
// 	// ARRANGE
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		expected_result;
// 	int		actual_result;

// 	// ACT
// 	userinput = "./push_swap 1 2 3 4 5 6 7 8";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	actual_result = ft_argv_is_duplicated(argv_simulation);
// 	expected_result = false;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result, actual_result);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_argv_size)
// {
// 	// ARRANGE
// 	char	**argv_simulation = NULL;
// 	char	*userinput;
// 	int		expected_size;
// 	int		actual_size;

// 	// ACT
// 	userinput = "./push_swap 1 2 3 4 5 6 7 8";
// 	argv_simulation = ft_split(userinput, ' ');
// 	expected_size = ft_minunit_array_counter(argv_simulation);
// 	actual_size = ft_argv_size(argv_simulation);

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	ft_array_clear(argv_simulation, expected_size);
// }

// MU_TEST(test_ft_reverse_rotate_ab)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		top_b = 999;
// 	int		second_b = 888;
// 	int		third_b = 777;
// 	int		bottom_b = 666;
// 	int		actual_result_a;
// 	int		actual_result_b;
// 	int		expected_result_a;
// 	int		expected_result_b;
// 	int		actual_size_a;
// 	int		expected_size_a;
// 	int		actual_size_b;
// 	int		expected_size_b;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	// ACT
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	stack_b = ft_lst_init(top_b);
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a);
// 	expected_size_b = ft_lstsize_int((t_list *)stack_b);
// 	ft_reverse_rotate_ab(&stack_a, &stack_b);
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_size_b = ft_lstsize_int((t_list *)stack_b);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
// 	expected_result_a = bottom_a;
// 	expected_result_b = bottom_b;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_result_b, actual_result_b);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	mu_assert_int_eq(expected_size_b, actual_size_b);
// 	ft_lstclear_single_ptr(stack_a);
// 	ft_lstclear_single_ptr(stack_b);
// }

// MU_TEST(test_ft_reverse_rotate)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		actual_result_a;
// 	int		expected_result_a;
// 	int		actual_size_a;
// 	int		expected_size_a;
// 	t_stack	*stack_a;

// 	// ACT
// 	stack_a = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	expected_result_a = bottom_a;
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a);
// 	ft_reverse_rotate(&stack_a);
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	ft_lstclear_single_ptr(stack_a);
// }

// MU_TEST(test_ft_rotate_ab)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		top_b = 999;
// 	int		second_b = 888;
// 	int		third_b = 777;
// 	int		bottom_b = 666;
// 	int		actual_result_a;
// 	int		actual_result_b;
// 	int		expected_result_a;
// 	int		expected_result_b;
// 	int		actual_size_a;
// 	int		actual_size_b;
// 	int		expected_size_a;
// 	int		expected_size_b;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	// ACT
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	stack_b = ft_lst_init(top_b);
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
// 	expected_result_a = second_a;
// 	expected_result_b = second_b;
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a);
// 	expected_size_b = ft_lstsize_int((t_list *)stack_b);
// 	ft_rotate_ab(&stack_a, &stack_b);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_size_b = ft_lstsize_int((t_list *)stack_b);

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_result_b, actual_result_b);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	mu_assert_int_eq(expected_size_b, actual_size_b);
// 	ft_lstclear_single_ptr(stack_a);
// 	ft_lstclear_single_ptr(stack_b);
// }

// MU_TEST(test_ft_rotate)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		actual_result_a;
// 	int		expected_result_a;
// 	int		expected_size;
// 	int		actual_size;
// 	t_stack	*stack_a;

// 	// ACT
// 	stack_a = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	expected_result_a = second_a;
// 	expected_size = ft_lstsize_int((t_list *)stack_a);
// 	ft_rotate(&stack_a);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_size = ft_lstsize_int((t_list *)stack_a);

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_size, actual_size);
// 	ft_lstclear_single_ptr(stack_a);
// }

// MU_TEST(test_ft_push_b)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		top_b = 999;
// 	int		second_b = 888;
// 	int		third_b = 777;
// 	int		bottom_b = 666;
// 	int		actual_result_a;
// 	int		actual_result_b;
// 	int		expected_result_a;
// 	int		expected_result_b;
// 	int		actual_size_a;
// 	int		actual_size_b;
// 	int		expected_size_a;
// 	int		expected_size_b;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	// ACT
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	stack_b = ft_lst_init(top_b);
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
// 	expected_result_a = second_a;
// 	expected_result_b = top_a;
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a) - 1;
// 	expected_size_b = ft_lstsize_int((t_list *)stack_b) + 1;
// 	ft_push_b(&stack_a, &stack_b);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_size_b = ft_lstsize_int((t_list *)stack_b);

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_result_b, actual_result_b);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	mu_assert_int_eq(expected_size_b, actual_size_b);
// 	ft_lstclear_single_ptr(stack_a);
// 	ft_lstclear_single_ptr(stack_b);
// }

// MU_TEST(test_ft_push_a)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		top_b = 999;
// 	int		second_b = 888;
// 	int		third_b = 777;
// 	int		bottom_b = 666;
// 	int		actual_result_a;
// 	int		actual_result_b;
// 	int		expected_result_a;
// 	int		expected_result_b;
// 	int		actual_size_a;
// 	int		actual_size_b;
// 	int		expected_size_a;
// 	int		expected_size_b;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	// ACT
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	stack_b = ft_lst_init(top_b);
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a) + 1;
// 	expected_size_b = ft_lstsize_int((t_list *)stack_b) - 1;
// 	ft_push_a(&stack_a, &stack_b);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_size_b = ft_lstsize_int((t_list *)stack_b);
// 	expected_result_a = top_b;
// 	expected_result_b = second_b;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_result_b, actual_result_b);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	mu_assert_int_eq(expected_size_b, actual_size_b);
// 	ft_lstclear_single_ptr(stack_a);
// 	ft_lstclear_single_ptr(stack_b);
// }

// MU_TEST(test_ft_swap_ab)
// {
// 	// ARRANGE
// 	int		top_a = 11;
// 	int		second_a = 22;
// 	int		third_a = 33;
// 	int		bottom_a = 44;
// 	int		top_b = 99;
// 	int		second_b = 88;
// 	int		third_b = 77;
// 	int		bottom_b = 66;
// 	int		actual_result_a;
// 	int		actual_result_b;
// 	int		expected_result_a;
// 	int		expected_result_b;
// 	int		actual_size_a;
// 	int		actual_size_b;
// 	int		expected_size_a;
// 	int		expected_size_b;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	// ACT
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	stack_a = ft_lst_init(top_a);
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(second_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(third_a));
// 	stack_a = ft_lst_addto_end(&stack_a, ft_lst_init(bottom_a));
// 	stack_b = ft_lst_init(top_b);
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(second_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(third_b));
// 	stack_b = ft_lst_addto_end(&stack_b, ft_lst_init(bottom_b));
// 	expected_size_a = ft_lstsize_int((t_list *)stack_a);
// 	expected_size_b = ft_lstsize_int((t_list *)stack_b);
// 	ft_swap_ab(&stack_a, &stack_b);
// 	actual_result_a = ft_lst_goto_head(stack_a)->nbr;
// 	actual_result_b = ft_lst_goto_head(stack_b)->nbr;
// 	actual_size_a = ft_lstsize_int((t_list *)stack_a);
// 	actual_size_b = ft_lstsize_int((t_list *)stack_b);
// 	expected_result_a = second_a;
// 	expected_result_b = second_b;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result_a, actual_result_a);
// 	mu_assert_int_eq(expected_result_b, actual_result_b);
// 	mu_assert_int_eq(expected_size_a, actual_size_a);
// 	mu_assert_int_eq(expected_size_b, actual_size_b);
// 	ft_lstclear_single_ptr(stack_a);
// 	ft_lstclear_single_ptr(stack_b);
// }

// MU_TEST(test_ft_swap)
// {
// 	// ARRANGE
// 	int		top = 11;
// 	int		second = 22;
// 	int		third = 33;
// 	int		bottom = 99;
// 	int		expected_result;
// 	int		actual_result;
// 	int		expected_size;
// 	int		actual_size;
// 	t_stack	*stack;

// 	// ACT
// 	stack = NULL;
// 	stack = ft_lst_init(top);
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
// 	expected_result = second;
// 	expected_size = ft_lstsize_int((t_list *)stack);

// 	ft_swap(&stack);
// 	actual_result = ft_lst_goto_head(stack)->nbr;;
// 	actual_size = ft_lstsize_int((t_list *)stack);

// 	// ASSERT
// 	mu_assert_int_eq(expected_result, actual_result);
// 	mu_assert_int_eq(expected_size, actual_size);
// 	ft_lstclear_single_ptr(stack);
// }

// MU_TEST(test_lst_delat_end)
// {
// 	// ARRANGE
// 	int		top = 11;
// 	int		second = 22;
// 	int		third = 33;
// 	int		bottom = 44;
// 	int		expected_result;
// 	int		actual_result;
// 	int		expected_size;
// 	int		actual_size;
// 	t_stack	*stack;

// 	// ACT
// 	stack = NULL;
// 	stack = ft_lst_init(top);
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(third));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
// 	expected_size = ft_lstsize_int((t_list *)stack) - 1;
// 	expected_result = third;

// 	stack = ft_lst_delat_end(stack);
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	actual_result = ft_lst_goto_end(stack)->nbr;

// 	// ASSERT
// 	mu_assert_int_eq(expected_result, actual_result);
// 	mu_assert_int_eq(expected_size, actual_size);
// 	ft_lstclear_single_ptr(stack);
// }

// MU_TEST(test_lst_delat_begin)
// {
// 	// ARRANGE
// 	int		top = 11;
// 	int		second = 22;
// 	int		thrid = 33;
// 	int		bottom = 44;
// 	int		expected_top;
// 	int		expected_bottom;
// 	int		expected_size;
// 	int		actual_top;
// 	int		actual_bottom;
// 	int		actual_size;
// 	t_stack	*stack;

// 	// ACT
// 	stack = NULL;
// 	stack = ft_lst_init(top);
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(thrid));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
// 	expected_size = ft_lstsize_int((t_list *)stack) - 1;
// 	expected_top = second;
// 	expected_bottom = bottom;
// 	stack = ft_lst_delat_begin(stack);
// 	stack = ft_lst_goto_head(stack);
// 	ft_lst_printf_int_content("lst_delat_begin >>>>>>", stack);
// 	actual_top = ft_lst_goto_head(stack)->nbr;
// 	actual_bottom = ft_lst_goto_end(stack)->nbr;
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	ft_printf("delat begin size = %d\n", ft_lstsize_int((t_list *)stack));

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	mu_assert_int_eq(expected_top, actual_top);
// 	mu_assert_int_eq(expected_bottom, actual_bottom);
// 	ft_lstclear_single_ptr(stack);
// }

// MU_TEST(test_lstsize_int_expec_3)
// {
// 	// ARRANGE
// 	int		top = 11;
// 	int		second = 22;
// 	int		bottom = 33;
// 	int		expected_size;
// 	int		actual_size;
// 	t_stack *stack;

// 	// ACT
// 	stack = NULL;
// 	stack = ft_lst_init(top);
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
// 	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
// 	actual_size = ft_lstsize_int((t_list *)stack);
// 	expected_size = 3;

// 	// ASSERT
// 	mu_assert_int_eq(expected_size, actual_size);
// 	ft_lstclear_single_ptr(stack);
// }


MU_TEST(test_lst_gotoend_head_and_beforeend)
{
	// ARRANGE
	int		top = 11;
	int		second = 22;
	int		thrid = 33;
	int		bottom = 44;
	int		expected_top;
	int		expected_bottom;
	int		expected_before_end;
	int		actual_top;
	int		actual_bottom;
	int		actual_before_end;
	int		expected_size;
	int		actual_size;
	t_stack	*stack;

	// ACT
	stack = NULL;
	stack = ft_lst_init(top);
	stack = ft_lst_addto_end(&stack, ft_lst_init(second));
	stack = ft_lst_addto_end(&stack, ft_lst_init(thrid));
	stack = ft_lst_addto_end(&stack, ft_lst_init(bottom));
	expected_top = top;
	expected_before_end = thrid;
	expected_bottom = bottom;
	actual_bottom = ft_lst_goto_end(stack)->nbr;
	actual_top = ft_lst_goto_head(stack)->nbr;
	actual_size = ft_lstsize_int((t_list *)stack);
	actual_before_end = ft_lst_goto_before_end(stack)->nbr;
	expected_size = 4;

	// ASSERT
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
	int		thrid = 33;
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
	stack = ft_lst_addto_end(&stack, ft_lst_init(thrid));
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
	actual_size = ft_lstsize_int((t_list *)stack);
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
	int		thrid = 33;
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
	stack = ft_lst_addto_begin(&stack, ft_lst_init(thrid));
	stack = ft_lst_addto_begin(&stack, ft_lst_init(bottom));
	expected_top = bottom;
	expected_bottom = top;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_top = stack->nbr;
	while (stack && stack->next)
		stack = stack->next;
	actual_bottom = stack->nbr;
	// actual_bottom = ft_lst_goto_end(stack)->nbr;
	while (stack && stack->prev)
		stack = stack->prev;
	actual_size = ft_lstsize_int((t_list *)stack);
	expected_size = 4;

	// ASSERT
	mu_assert_int_eq(expected_top, actual_top);
	mu_assert_int_eq(expected_bottom, actual_bottom);
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
	// MU_RUN_TEST(test_lst_init_non_nbr);
	MU_RUN_TEST(test_lst_addto_begin);
	MU_RUN_TEST(test_lst_addto_end);
	MU_RUN_TEST(test_lst_gotoend_head_and_beforeend);
	// MU_RUN_TEST(test_lstsize_int_expec_3);
	// MU_RUN_TEST(test_lst_delat_begin);
	// MU_RUN_TEST(test_lst_delat_end);
}

// MU_TEST_SUITE(swap_tests)
// {
// 	MU_RUN_TEST(test_ft_swap);
// 	MU_RUN_TEST(test_ft_swap_ab);
// }

// MU_TEST_SUITE(push_tests)
// {
// 	MU_RUN_TEST(test_ft_push_a);
// 	MU_RUN_TEST(test_ft_push_b);
// }

// MU_TEST_SUITE(rotate_tests)
// {
// 	MU_RUN_TEST(test_ft_rotate);
// 	MU_RUN_TEST(test_ft_rotate_ab);
// 	MU_RUN_TEST(test_ft_reverse_rotate);
// 	MU_RUN_TEST(test_ft_reverse_rotate_ab);
// }

// MU_TEST_SUITE(argv_tests)
// {
// 	MU_RUN_TEST(test_argv_size);
// 	MU_RUN_TEST(test_argv_is_duplicated_false);
// 	MU_RUN_TEST(test_argv_is_duplicated_true);
// 	MU_RUN_TEST(test_buildstack_argv);
// }

// MU_TEST_SUITE(sorting_tests)
// {
// 	MU_RUN_TEST(test_sort_2_nbrs_without_zero);
// 	MU_RUN_TEST(test_sort_2_nbrs_with_zero);
// 	MU_RUN_TEST(test_sort_3_nbrs_highest_at_middle);
// 	MU_RUN_TEST(test_sort_3_nbrs_highest_first);
	// MU_RUN_TEST(test_sort_3_nbrs_highest_last);
// }

int main(void)
{
	MU_RUN_SUITE(linked_list_tests);
	// MU_RUN_SUITE(swap_tests);
	// MU_RUN_SUITE(push_tests);
	// MU_RUN_SUITE(rotate_tests);
	// MU_RUN_SUITE(argv_tests);
	// MU_RUN_SUITE(sorting_tests);
	MU_REPORT();
	return (0);
}


int	ft_minunit_array_counter(char **array)
{
	int arr_size;

	arr_size = 0;
	while (array[arr_size] != NULL)
	{
		arr_size++;
		if (array[arr_size] == NULL)
		{
			arr_size--;
			break ;
		}
	}
	return (arr_size);
}

void	ft_array_clear(char **array, int arr_size)
{
	while (arr_size >= 0)
	{
		free(array[arr_size]);
		arr_size--;
	}
	free(array);
}

void	ft_array_printer(char **array, int arr_size)
{
	int index;

	index = arr_size;
	while (index >= 0)
	{
		ft_printf("argv_simulation = %s\n", (array[index]));
		index--;
	}
}

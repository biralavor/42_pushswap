/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_miunit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/19 15:18:24 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"
#include "../../program_to_test/src/ft_argv_validation.c"
#include "../../program_to_test/src/ft_lst_map_all.c"
#include "../../program_to_test/src/ft_lst_map_indexers.c"
#include "../../program_to_test/src/ft_lst_init.c"
#include "../../program_to_test/src/ft_lst_goto.c"
#include "../../program_to_test/src/ft_lst_addto.c"
#include "../../program_to_test/src/ft_lst_deletes.c"
#include "../../program_to_test/src/ft_lst_clear.c"
#include "../../program_to_test/src/ft_swap.c"
#include "../../program_to_test/src/ft_push.c"
#include "../../program_to_test/src/ft_rotate.c"
#include "../../program_to_test/src/ft_do_push_fts.c"
#include "../../program_to_test/src/ft_do_rev_rotate_fts.c"
#include "../../program_to_test/src/ft_do_rotate_fts.c"
#include "../../program_to_test/src/ft_do_swap_fts.c"
#include "../../program_to_test/src/ft_do_sort.c"
#include "../../program_to_test/src/ft_sort_until3.c"
#include "../../program_to_test/src/ft_sort_until4.c"
#include "../../program_to_test/src/ft_sort_5_or_more.c"
// #include "minunit_utils.c"
// #include "minunit_utils.h"

// TODO:
// make test for a list with four or more numbers
// make test for signs (- +)
// make test for non-numbers input

int		ft_minunit_array_counter(char **array);
void	ft_array_clear(char **array, int arr_size);
void	ft_array_printer(char **array, int arr_size);


MU_TEST(test_3rd_miastep_get_cost)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		actual_top_a;
	int		expected_bottom_a;
	int		actual_bottom_a;
	int		expected_cost;
	int		actual_cost;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[8]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	expected_cost = 0;  // stack_b->nbr[8]
	actual_size = ft_lst_size(stack_a);
	ft_lst_map_all_indexers(&stack_a);
	ft_push_b_all_but_three(&stack_a, &stack_b);
	ft_sort_three_nbrs(&stack_a);
	ft_lst_get_cost(&stack_a, &stack_b);
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	ft_lst_printf_data_content("get_cost stack_a:", stack_a);
	ft_lst_printf_data_content("get_cost stack_b:", stack_b);
	actual_cost = stack_b->next->cost_b;
	// ASSERT
	mu_assert_int_eq(expected_cost, actual_cost);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_3rd_miastep_map_get_target_position)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		actual_top_a;
	int		expected_bottom_a;
	int		actual_bottom_a;
	// int		expected_target_pos;
	// int		actual_target_pos;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[8]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	// expected_target_pos = 5;  // stack_b->origin[5]
	actual_size = ft_lst_size(stack_a);
	ft_push_b_all_but_three(&stack_a, &stack_b);
	ft_sort_three_nbrs(&stack_a);
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;

	ft_lst_get_target_position(&stack_a, &stack_b);
	// actual_target_pos = stack_b->target;

	// ASSERT
	// mu_assert_int_eq(expected_target_pos, actual_target_pos);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_3rd_miastep_map_lowest_final_pos)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		actual_top_a;
	int		expected_bottom_a;
	int		actual_bottom_a;
	int		expected_lowest_final_pos_pos;
	int		expected_lowest_final_pos_nbr;
	int		actual_lowest_final_pos_pos;
	int		actual_lowest_final_pos_nbr;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[8]);

	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_actual_position(&stack);
	ft_lst_map_final_pos(&stack, expected_size);
	expected_lowest_final_pos_pos = 3; // argv[3] = 1;
	expected_lowest_final_pos_nbr = ft_atoi(argv_simulation[expected_lowest_final_pos_pos]);

	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;
	actual_lowest_final_pos_pos = ft_lst_map_lowest_final_position(&stack);
	actual_bottom_a = ft_lst_goto_end(stack)->nbr;
	actual_lowest_final_pos_nbr = stack->next->next->nbr;
	

	// ASSERT
	mu_assert_int_eq(expected_lowest_final_pos_pos, actual_lowest_final_pos_pos);
	mu_assert_int_eq(expected_lowest_final_pos_nbr, actual_lowest_final_pos_nbr);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_four_nbrs_v04)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		expected_bottom_a;
	int		actual_top_a;
	int		actual_bottom_a;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 7 10 5 12";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[3]);
	expected_bottom_a = ft_atoi(argv_simulation[4]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_lst_printf_data_content("stack_a before sort_four_nbrs:", stack_a);
	ft_sort_four_nbrs(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);
	ft_lst_printf_data_content("stack_a after sort_four_nbrs:", stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_four_nbrs_v03)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		expected_bottom_a;
	int		actual_top_a;
	int		actual_bottom_a;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 7 5 12 10";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[2]);
	expected_bottom_a = ft_atoi(argv_simulation[3]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_sort_four_nbrs(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_four_nbrs_v02)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		expected_bottom_a;
	int		actual_top_a;
	int		actual_bottom_a;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 5 12 10 7";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_sort_four_nbrs(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_four_nbrs_v01)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		expected_bottom_a;
	int		actual_top_a;
	int		actual_bottom_a;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 12 5 7 10";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[2]);
	expected_bottom_a = ft_atoi(argv_simulation[1]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_sort_four_nbrs(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_2nd_miastep_push_b_all_but3_sort_a)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size_before_push;
	int		actual_size_before_push;
	int		expected_top_a_before_push;
	int		expected_bottom_a_before_push;
	int		actual_top_a_before_push;
	int		actual_bottom_a_before_push;

	int		expected_top_a_after_push;
	int		expected_top_b_after_push;
	int		expected_bottom_a_after_push;
	int		expected_bottom_b_after_push;
	int		actual_top_a_after_push;
	int		actual_top_b_after_push;
	int		actual_bottom_a_after_push;
	int		actual_bottom_b_after_push;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 2 42 11 4 8 3";
	argv_simulation = ft_split(userinput, ' ');
	expected_size_before_push = ft_minunit_array_counter(argv_simulation);
	expected_top_a_before_push = ft_atoi(argv_simulation[1]);
	expected_bottom_a_before_push = ft_atoi(argv_simulation[6]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_actual_position(&stack_a);
	ft_lst_map_final_pos(&stack_a, expected_size_before_push);

	actual_size_before_push = ft_lst_size(stack_a);
	actual_top_a_before_push = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a_before_push = ft_lst_goto_end(stack_a)->nbr;

	ft_push_b_all_but_three(&stack_a, &stack_b);
	ft_sort_three_nbrs(&stack_a);

	expected_top_a_after_push = ft_atoi(argv_simulation[6]);
	expected_bottom_a_after_push = ft_atoi(argv_simulation[5]);
	expected_bottom_b_after_push = ft_atoi(argv_simulation[1]);
	expected_top_b_after_push = ft_atoi(argv_simulation[3]);
	actual_top_a_after_push = ft_lst_goto_head(stack_a)->nbr;
	actual_top_b_after_push = ft_lst_goto_head(stack_b)->nbr;
	actual_bottom_a_after_push = ft_lst_goto_end(stack_a)->nbr;
	actual_bottom_b_after_push = ft_lst_goto_end(stack_b)->nbr;
	// ASSERT
	mu_assert_int_eq(expected_top_a_after_push, actual_top_a_after_push);
	mu_assert_int_eq(expected_top_b_after_push, actual_top_b_after_push);
	mu_assert_int_eq(expected_bottom_b_after_push, actual_bottom_b_after_push);
	mu_assert_int_eq(expected_bottom_a_after_push, actual_bottom_a_after_push);
	mu_assert_int_eq(expected_size_before_push, actual_size_before_push);
	mu_assert_int_eq(expected_top_a_before_push, actual_top_a_before_push);
	mu_assert_int_eq(expected_bottom_a_before_push, actual_bottom_a_before_push);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size_before_push);
}

MU_TEST(test_1st_miastep_push_b_all_but3)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size_before_push;
	int		actual_size_before_push;
	int		expected_top_a_before_push;
	int		expected_bottom_a_before_push;
	int		actual_top_a_before_push;
	int		actual_bottom_a_before_push;

	int		expected_top_a_after_push;
	int		expected_top_b_after_push;
	int		expected_bottom_a_after_push;
	int		expected_bottom_b_after_push;
	int		actual_top_a_after_push;
	int		actual_top_b_after_push;
	int		actual_bottom_a_after_push;
	int		actual_bottom_b_after_push;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 2 42 11 4 8 3";
	argv_simulation = ft_split(userinput, ' ');
	expected_size_before_push = ft_minunit_array_counter(argv_simulation);
	expected_top_a_before_push = ft_atoi(argv_simulation[1]);
	expected_bottom_a_before_push = ft_atoi(argv_simulation[6]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_actual_position(&stack_a);
	ft_lst_map_final_pos(&stack_a, expected_size_before_push);

	actual_size_before_push = ft_lst_size(stack_a);
	actual_top_a_before_push = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a_before_push = ft_lst_goto_end(stack_a)->nbr;

	ft_push_b_all_but_three(&stack_a, &stack_b);

	expected_top_a_after_push = ft_atoi(argv_simulation[4]);
	expected_bottom_a_after_push = ft_atoi(argv_simulation[6]);
	expected_bottom_b_after_push = ft_atoi(argv_simulation[1]);
	expected_top_b_after_push = ft_atoi(argv_simulation[3]);
	actual_top_a_after_push = ft_lst_goto_head(stack_a)->nbr;
	actual_top_b_after_push = ft_lst_goto_head(stack_b)->nbr;
	actual_bottom_a_after_push = ft_lst_goto_end(stack_a)->nbr;
	actual_bottom_b_after_push = ft_lst_goto_end(stack_b)->nbr;
	// ASSERT
	mu_assert_int_eq(expected_top_a_after_push, actual_top_a_after_push);
	mu_assert_int_eq(expected_top_b_after_push, actual_top_b_after_push);
	mu_assert_int_eq(expected_bottom_b_after_push, actual_bottom_b_after_push);
	mu_assert_int_eq(expected_bottom_a_after_push, actual_bottom_a_after_push);
	mu_assert_int_eq(expected_size_before_push, actual_size_before_push);
	mu_assert_int_eq(expected_top_a_before_push, actual_top_a_before_push);
	mu_assert_int_eq(expected_bottom_a_before_push, actual_bottom_a_before_push);
	ft_lstclear_single_ptr(stack_a);
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size_before_push);
}

MU_TEST(test_1st_miastep_final_pos_index)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		actual_top_a;
	int		expected_bottom_a;
	int		actual_bottom_a;
	int		expected_highest_final_pos;
	int		actual_highest_final_pos;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2 42 0 4 8 3 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[8]);
	expected_highest_final_pos = expected_size - 1;

	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_actual_position(&stack);
	ft_lst_map_final_pos(&stack, expected_size);

	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;

	while (stack->origin <= 2)
	{
		stack = stack->next;
		if (stack->origin == 2)
			actual_highest_final_pos = stack->final_pos;
	}
	actual_bottom_a = ft_lst_goto_end(stack)->nbr;

	// ASSERT
	mu_assert_int_eq(expected_highest_final_pos, actual_highest_final_pos);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_1st_miastep_pos_index)
{
	// ARRANGE
	t_stack	*stack;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		expected_size;
	int		actual_size;
	int		expected_top_a;
	int		actual_top_a;
	int		expected_bottom_a;
	int		actual_bottom_a;
	int		expected_fith_position;
	int		actual_fith_position;

	// ACT
	stack = NULL;
	userinput = "./push_swap 2 42 0 4 8 3 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[8]);
	expected_fith_position = ft_atoi(argv_simulation[5]);

	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_actual_position(&stack);

	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;
	while (stack->origin <= 5)
	{
		stack = stack->next;
		if (stack->origin == 5)
			actual_fith_position = stack->nbr;
	}
	actual_bottom_a = ft_lst_goto_end(stack)->nbr;
	// ASSERT
	mu_assert_int_eq(expected_fith_position, actual_fith_position);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

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
	stack = ft_sort_three_nbrs(&stack);
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
	stack = ft_sort_three_nbrs(&stack);
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
	stack = ft_sort_three_nbrs(&stack);
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
	stack = ft_sort_three_nbrs(&stack);
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
	stack = ft_sort_three_nbrs(&stack);
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
	stack = ft_sort_three_nbrs(&stack);
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
	actual_result = ft_argv_is_duplicated(argv_simulation);
	expected_result = true;

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
	actual_result = ft_argv_is_duplicated(argv_simulation);
	expected_result = false;

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
	ft_lst_printf_data_content("stack_a", stack_a);
	ft_lst_printf_data_content("stack_b", stack_b);

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

MU_TEST_SUITE(argv_tests)
{
	MU_RUN_TEST(test_argv_size);
	MU_RUN_TEST(test_argv_is_duplicated_false);
	MU_RUN_TEST(test_argv_is_duplicated_true);
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

MU_TEST_SUITE(miacombeau_1st_and_2nd_steps_tests)
{
	MU_RUN_TEST(test_1st_miastep_pos_index);
	MU_RUN_TEST(test_1st_miastep_final_pos_index);
	MU_RUN_TEST(test_1st_miastep_push_b_all_but3);
	MU_RUN_TEST(test_2nd_miastep_push_b_all_but3_sort_a);
}

MU_TEST_SUITE(sorting_4_nbrs_tests)
{
	MU_RUN_TEST(test_sort_four_nbrs_v01);
	MU_RUN_TEST(test_sort_four_nbrs_v02);
	MU_RUN_TEST(test_sort_four_nbrs_v03);
	MU_RUN_TEST(test_sort_four_nbrs_v04);
}

MU_TEST_SUITE(miacombeau_3rd_step_tests)
{
	MU_RUN_TEST(test_3rd_miastep_map_lowest_final_pos);
	MU_RUN_TEST(test_3rd_miastep_get_cost);
	MU_RUN_TEST(test_3rd_miastep_map_get_target_position);
}

int main(void)
{
	MU_RUN_SUITE(linked_list_tests);
	MU_RUN_SUITE(swap_tests);
	MU_RUN_SUITE(push_tests);
	MU_RUN_SUITE(rotate_tests);
	MU_RUN_SUITE(argv_tests);
	MU_RUN_SUITE(sorting_2_or_3_nbrs_tests);
	MU_RUN_SUITE(miacombeau_1st_and_2nd_steps_tests);
	MU_RUN_SUITE(sorting_4_nbrs_tests);
	MU_RUN_SUITE(miacombeau_3rd_step_tests);
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

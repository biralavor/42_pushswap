/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04_miasteps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:43:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"


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
	expected_top_a = ft_atoi(argv_simulation[5]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	expected_cost = 2;  // stack_b[3]->nbr = 4
	actual_size = ft_lst_size(stack_a);
	ft_lst_map_all_indexers(&stack_a);
	ft_push_b_all_but_three(&stack_a, &stack_b);
	ft_sort_a_with_three_nbrs(&stack_a);
	ft_lst_get_cost(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_cost = stack_b->next->next->cost_b;

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
	int		expected_top_b;
	int		actual_top_b;
	int		expected_bottom_a;
	int		actual_bottom_a;
	int		expected_target_pos;
	int		actual_target_pos;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_b = ft_atoi(argv_simulation[7]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	expected_target_pos = 2; // should be stack_b->target
	actual_size = ft_lst_size(stack_a);
	ft_push_b_all_but_three(&stack_a, &stack_b);
	ft_sort_a_with_three_nbrs(&stack_a);
	ft_lst_get_target_position(&stack_a, &stack_b);

	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_top_b = ft_lst_goto_head(stack_b)->nbr;
	actual_target_pos = stack_b->target;

	// ASSERT
	mu_assert_int_eq(expected_target_pos, actual_target_pos);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_b, actual_top_b);
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
	expected_lowest_final_pos_pos = 2;  //should be stack->origin[2]
	expected_lowest_final_pos_nbr = ft_atoi(argv_simulation[3]); // argv[3] = 1;

	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;
	actual_lowest_final_pos_pos = ft_lst_map_lowest_final_position(&stack);
	actual_bottom_a = ft_lst_goto_end(stack)->nbr;
	actual_lowest_final_pos_nbr = 0;
	while (stack)
	{
		if (stack->origin == 2)
		{
			actual_lowest_final_pos_pos = stack->origin;
			actual_lowest_final_pos_nbr = stack->nbr;
			break ;
		}
		stack = stack->next;
	}

	// ASSERT
	mu_assert_int_eq(expected_lowest_final_pos_pos, actual_lowest_final_pos_pos);
	mu_assert_int_eq(expected_lowest_final_pos_nbr, actual_lowest_final_pos_nbr);
	mu_assert_int_eq(expected_size, actual_size);
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	ft_lstclear_single_ptr(stack);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_sort_four_nbrs_v05)
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
	userinput = "./push_swap 2 3 1 0";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[4]);
	expected_bottom_a = ft_atoi(argv_simulation[2]);

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_do_sort(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
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
	ft_sort_four_or_more_nbr(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
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
	ft_sort_four_or_more_nbr(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
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
	ft_sort_four_or_more_nbr(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
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
	ft_sort_four_or_more_nbr(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);

	// ASSERT
	mu_assert_int_eq(expected_top_a, actual_top_a);
	mu_assert_int_eq(expected_bottom_a, actual_bottom_a);
	mu_assert_int_eq(expected_size, actual_size);
	ft_lstclear_single_ptr(stack_a);
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
	ft_sort_a_with_three_nbrs(&stack_a);

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
	userinput = "./push_swap 1 2 42 0 4 8 3 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[9]);
	expected_highest_final_pos = expected_size;

	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_actual_position(&stack);
	ft_lst_map_final_pos(&stack, expected_size + 1);
	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;
	actual_highest_final_pos = 0;
	while (stack)
	{
		if (stack->origin == 2)
		{
			actual_highest_final_pos = stack->final_pos;
			break ;
		}
		stack = stack->next;
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
	userinput = "./push_swap 2 42 0 4 8 3 31 27 1 100 200 150 80";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[13]);
	expected_fith_position = ft_atoi(argv_simulation[6]);

	stack = ft_lts_buildstack_argv(&stack, argv_simulation);
	ft_lst_map_actual_position(&stack);
	actual_size = ft_lst_size(stack);
	actual_top_a = ft_lst_goto_head(stack)->nbr;
	actual_fith_position = 0;
	while (stack)
	{
		if (stack->origin == 5)
		{
			actual_fith_position = stack->nbr;
			break ;
		}
		stack = stack->next;
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
	MU_RUN_TEST(test_sort_four_nbrs_v05);
}

MU_TEST_SUITE(miacombeau_3rd_step_tests)
{
	MU_RUN_TEST(test_3rd_miastep_map_lowest_final_pos);
	MU_RUN_TEST(test_3rd_miastep_map_get_target_position);
	MU_RUN_TEST(test_3rd_miastep_get_cost);
}

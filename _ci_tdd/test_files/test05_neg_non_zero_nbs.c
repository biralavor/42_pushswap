/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_neg_non_zero_nbs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:37:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"

MU_TEST(test_3neg_min_at_thrid_pos_big_nbrs_v02)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		xpect_size;
	int		actual_size;
	int		xpect_top_a;
	int		xpect_second_a;
	int		xpect_fith_a;
	int		xpect_bottom_a;
	int		xpect_sorted;
	int		actual_top_a;
	int		actual_second_a;
	int		actual_fith_a;
	int		actual_bottom_a;
	int		actual_sorted;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 1285205424 1433966465 -1748883138 324282304 1821881335 -881795666";
	argv_simulation = ft_split(userinput, ' ');
	xpect_size = ft_minunit_array_counter(argv_simulation);
	xpect_top_a = ft_atoi(argv_simulation[3]);
	xpect_second_a = ft_atoi(argv_simulation[6]);
	xpect_fith_a = ft_atoi(argv_simulation[2]);
	xpect_bottom_a = ft_atoi(argv_simulation[5]);
	xpect_sorted = true;

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_do_sort(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_second_a = ft_lst_goto_head(stack_a)->next->nbr;
	actual_fith_a = ft_lst_goto_before_end(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);
	actual_sorted = ft_is_sorted(stack_a);

	// ASSERT
	mu_assert_int_eq(xpect_size, actual_size);
	mu_assert_int_eq(xpect_top_a, actual_top_a);
	mu_assert_int_eq(xpect_second_a, actual_second_a);
	mu_assert_int_eq(xpect_fith_a, actual_fith_a);
	mu_assert_int_eq(xpect_bottom_a, actual_bottom_a);
	mu_assert_int_eq(xpect_sorted, actual_sorted);
	ft_lstclear_single_ptr(stack_a);
	ft_array_clear(argv_simulation, xpect_size);
}

MU_TEST(test_3neg_min_at_thrid_pos_big_nbrs_v01)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		xpect_size;
	int		actual_size;
	int		xpect_top_a;
	int		xpect_second_a;
	int		xpect_fith_a;
	int		xpect_bottom_a;
	int		xpect_sorted;
	int		actual_top_a;
	int		actual_second_a;
	int		actual_fith_a;
	int		actual_bottom_a;
	int		actual_sorted;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap -585074721 371934173 -1486065689 -1039864857 1483818456 -1140871206";
	argv_simulation = ft_split(userinput, ' ');
	xpect_size = ft_minunit_array_counter(argv_simulation);
	xpect_top_a = ft_atoi(argv_simulation[3]);
	xpect_second_a = ft_atoi(argv_simulation[6]);
	xpect_fith_a = ft_atoi(argv_simulation[2]);
	xpect_bottom_a = ft_atoi(argv_simulation[5]);
	xpect_sorted = true;

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_do_sort(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_second_a = ft_lst_goto_head(stack_a)->next->nbr;
	actual_fith_a = ft_lst_goto_before_end(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);
	actual_sorted = ft_is_sorted(stack_a);

	// ASSERT
	mu_assert_int_eq(xpect_size, actual_size);
	mu_assert_int_eq(xpect_top_a, actual_top_a);
	mu_assert_int_eq(xpect_second_a, actual_second_a);
	mu_assert_int_eq(xpect_fith_a, actual_fith_a);
	mu_assert_int_eq(xpect_bottom_a, actual_bottom_a);
	mu_assert_int_eq(xpect_sorted, actual_sorted);
	ft_lstclear_single_ptr(stack_a);
	ft_array_clear(argv_simulation, xpect_size);
}

MU_TEST(test_3neg_min_at_thrid_pos)
{
	// ARRANGE
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_simulation = NULL;
	char	*userinput;
	int		xpect_size;
	int		actual_size;
	int		xpect_top_a;
	int		xpect_second_a;
	int		xpect_fith_a;
	int		xpect_bottom_a;
	int		xpect_sorted;
	int		actual_top_a;
	int		actual_second_a;
	int		actual_fith_a;
	int		actual_bottom_a;
	int		actual_sorted;

	// ACT
	stack_a = NULL;
	stack_b = NULL;
	userinput = "./push_swap 1 2 -3 -1 3 -2";
	argv_simulation = ft_split(userinput, ' ');
	xpect_size = ft_minunit_array_counter(argv_simulation);
	xpect_top_a = ft_atoi(argv_simulation[3]);
	xpect_second_a = ft_atoi(argv_simulation[6]);
	xpect_fith_a = ft_atoi(argv_simulation[2]);
	xpect_bottom_a = ft_atoi(argv_simulation[5]);
	xpect_sorted = true;

	stack_a = ft_lts_buildstack_argv(&stack_a, argv_simulation);
	ft_lst_map_all_indexers(&stack_a);
	ft_do_sort(&stack_a, &stack_b);
	actual_top_a = ft_lst_goto_head(stack_a)->nbr;
	actual_second_a = ft_lst_goto_head(stack_a)->next->nbr;
	actual_fith_a = ft_lst_goto_before_end(stack_a)->nbr;
	actual_bottom_a = ft_lst_goto_end(stack_a)->nbr;
	actual_size = ft_lst_size(stack_a);
	actual_sorted = ft_is_sorted(stack_a);

	// ASSERT
	mu_assert_int_eq(xpect_size, actual_size);
	mu_assert_int_eq(xpect_top_a, actual_top_a);
	mu_assert_int_eq(xpect_second_a, actual_second_a);
	mu_assert_int_eq(xpect_fith_a, actual_fith_a);
	mu_assert_int_eq(xpect_bottom_a, actual_bottom_a);
	mu_assert_int_eq(xpect_sorted, actual_sorted);
	ft_lstclear_single_ptr(stack_a);
	ft_array_clear(argv_simulation, xpect_size);
}

MU_TEST(test_zero_numbers_pluszero)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 0 -1 +0 -8 -5 -31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_is_not_duplicated(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_zero_numbers_zerozero)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 0 -1 00 -8 -5 -31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_is_not_duplicated(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_signs_plus_at_double)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 -42 -1 -4 ++8 -5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_signs_plus_at_once)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 -42 -1 -4 +8 -5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = true;
	
	actual_validation = ft_argv_is_not_duplicated(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_signs_at_end)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 -42 -1 -4 8 -5 31 -27 -";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_signs_at_middle)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap -2 -42 -1 -4 8 - 5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_signs_at_beginning)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap - 2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_non_nbr_two_nons_at_end)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap 2 42 1 4 8 -5 31c 27c";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_non_nbr_at_end)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap 2 42 1 4 8 5 31 -27c";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_non_nbr_at_middle)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap 2 42 1 4 8b9 5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_non_nbr_at_beginning)
{
	// ARRANGE
	char	**argv_simulation = NULL;
	char	*userinput;
	bool	expected_validation;
	bool	actual_validation;

	// ACT
	userinput = "./push_swap a 2 42 1 4 8 5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_validation = false;
	
	actual_validation = ft_argv_valid_sign_and_not_alpha(argv_simulation);

	// ASSERT
	mu_assert_int_eq(expected_validation, actual_validation);
}

MU_TEST(test_negative_nbr_five_negs)
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
	userinput = "./push_swap -2 42 1 -4 -8 -5 -31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[7]);
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

MU_TEST(test_negative_nbr_two_negs)
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
	userinput = "./push_swap 2 42 1 -4 8 5 -31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[7]);
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_negative_nbr_all_negs_6nbrs)
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
	userinput = "./push_swap -42 -2 -10 -20 -11 -1";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
	expected_bottom_a = ft_atoi(argv_simulation[6]);

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

MU_TEST(test_negative_nbr_two_negs_at_end_on_top)
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
	userinput = "./push_swap 2 42 1 4 8 5 -27 -31";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[8]);
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_negative_nbr_two_negs_at_end_not_on_top)
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
	userinput = "./push_swap 2 42 1 4 8 5 -31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[7]);
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_negative_nbr_at_end)
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
	userinput = "./push_swap 2 42 1 4 8 5 31 -27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[8]);
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_negative_nbr_at_middle)
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
	userinput = "./push_swap 2 42 1 -4 8 5 31 27";
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST(test_negative_nbr_at_beginning)
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
	userinput = "./push_swap -2 42 1 4 8 5 31 27";
	argv_simulation = ft_split(userinput, ' ');
	expected_size = ft_minunit_array_counter(argv_simulation);
	expected_top_a = ft_atoi(argv_simulation[1]);
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
	ft_lstclear_single_ptr(stack_b);
	ft_array_clear(argv_simulation, expected_size);
}

MU_TEST_SUITE(negative_numbers_test)
{
	MU_RUN_TEST(test_negative_nbr_at_beginning);
	MU_RUN_TEST(test_negative_nbr_at_middle);
	MU_RUN_TEST(test_negative_nbr_at_end);
	MU_RUN_TEST(test_negative_nbr_two_negs_at_end_not_on_top);
	MU_RUN_TEST(test_negative_nbr_two_negs_at_end_on_top);
	MU_RUN_TEST(test_negative_nbr_all_negs_6nbrs);
	MU_RUN_TEST(test_negative_nbr_two_negs);
	MU_RUN_TEST(test_negative_nbr_five_negs);
}

MU_TEST_SUITE(non_numbers_test)
{
	MU_RUN_TEST(test_non_nbr_at_beginning);
	MU_RUN_TEST(test_non_nbr_at_middle);
	MU_RUN_TEST(test_non_nbr_at_end);
	MU_RUN_TEST(test_non_nbr_two_nons_at_end);
	MU_RUN_TEST(test_signs_at_beginning);
	MU_RUN_TEST(test_signs_at_middle);
	MU_RUN_TEST(test_signs_at_end);
	MU_RUN_TEST(test_signs_plus_at_once);
	MU_RUN_TEST(test_signs_plus_at_double);
}

MU_TEST_SUITE(zero_tests)
{
	MU_RUN_TEST(test_zero_numbers_zerozero);
	MU_RUN_TEST(test_zero_numbers_pluszero);
}

MU_TEST_SUITE(three_neg_nbrs_tests)
{
	MU_RUN_TEST(test_3neg_min_at_thrid_pos);
	MU_RUN_TEST(test_3neg_min_at_thrid_pos_big_nbrs_v01);
	MU_RUN_TEST(test_3neg_min_at_thrid_pos_big_nbrs_v02);
}

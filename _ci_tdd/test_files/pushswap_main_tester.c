/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main_tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:49:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"

#include "../../program_to_test/src/ft_argv_utils.c"
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
#include "../../program_to_test/src/ft_do_move_with_cost.c"
#include "../../program_to_test/src/ft_sort_until3.c"
#include "../../program_to_test/src/ft_sort_4_or_more.c"
#include "../../program_to_test/src/ft_sort_4_utils.c"

#include "test_minunit_utils.c"
#include "test01_list_init.c"
#include "test02_do_moves.c"
#include "test03_argv.c"
#include "test04_miasteps.c"
#include "test05_neg_non_zero_nbs.c"

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
	
	MU_RUN_SUITE(negative_numbers_test);
	MU_RUN_SUITE(non_numbers_test);
	MU_RUN_SUITE(zero_tests);
	MU_RUN_SUITE(three_neg_nbrs_tests);
	MU_REPORT();
	return (0);
}

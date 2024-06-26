/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/26 12:21:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				origin;
	int				final_pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_lst_init(int value);
t_stack	*ft_lst_goto_end(t_stack *stack);
t_stack	*ft_lst_goto_head(t_stack *stack);
t_stack	*ft_lst_goto_before_end(t_stack *stack);
t_stack	*ft_lst_addto_end(t_stack **stack, t_stack *new);
t_stack	*ft_lst_addto_begin(t_stack **stack, t_stack *new);
t_stack	*ft_lst_delat_begin(t_stack *stack);
t_stack	*ft_lst_delat_end(t_stack *stack);
void	ft_lstclear_double_ptr(t_stack **stack);
void	ft_lstclear_single_ptr(t_stack *stack);
void	ft_lst_printf_data_content(char *msg, t_stack *stack);
t_stack	*ft_lts_buildstack_argv(t_stack **stack, char **argv);
bool	ft_is_sign(int c);
bool	ft_is_space(int c);
bool	ft_argv_is_duplicated(char **argv);
int		ft_argv_size(char **argv);
bool	ft_argv_validation(char **argv);
/* new functions for push_swap to be added in LIBFT */

int		ft_lst_size(t_stack *stack);
void	ft_swap(t_stack **stack);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
/* basic push_swap functions */

bool	ft_is_sorted(t_stack *stack);
/* sorting validation functions */

int		ft_lst_map_highest_pos(t_stack *list);
void	ft_do_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_sort_two_nbrs(t_stack **stack);
t_stack	*ft_sort_three_nbrs(t_stack **stack);
/* sorting functions if list has until 3 numbers */

void	ft_sort_four_nbrs(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five_or_more_nbr(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b_all_but_three(t_stack **stack_a, t_stack **stack_b);
int		ft_lst_get_target(t_stack **stack_a, int b_end_pos,
			int target_end_pos, int target_pos);
void	ft_lst_get_target_position(t_stack **stack_a, t_stack **stack_b);
void	ft_lst_map_all_indexers(t_stack **stack);
void	ft_lst_map_actual_position(t_stack **stack);
void	ft_lst_map_final_pos(t_stack **stack, int stack_size);
int		ft_lst_map_lowest_final_position(t_stack **stack);
void	ft_lst_shift_stack(t_stack **stack_a);
void	ft_lst_get_cost(t_stack **stack_a, t_stack **stack_b);
int		abs_nbr(int nbr);
void	ft_lst_do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	ft_do_move_after_cheapest(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b);
/* sorting functions if list has 4 or more numbers */

void	ft_rev_rotate_ab_with_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	ft_rotate_ab_with_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	ft_rotate_a_with_cost(t_stack **stack_a, int *cost_a);
void	ft_rotate_b_with_cost(t_stack **stack_b, int *cost_b);
/* sorting functions take takes the cheapest cost and do the move */

void	ft_do_swap_a(t_stack **stack);
void	ft_do_swap_b(t_stack **stack);
void	ft_do_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_do_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_do_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **source, t_stack **destiny);
void	ft_do_rotate_a(t_stack **stack);
void	ft_do_rotate_b(t_stack **stack);
void	ft_do_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_do_reverse_rotate_a(t_stack **stack);
void	ft_do_reverse_rotate_b(t_stack **stack);
void	ft_do_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
/* functions that call sorting and print the action on STDOUT */

#endif
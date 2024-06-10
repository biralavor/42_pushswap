/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/10 11:10:55 by umeneses         ###   ########.fr       */
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
	int				cost;
	int				pos;
	int				weight;
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
void	ft_lst_printf_int_content(char *msg, t_stack *stack);
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

void	ft_lst_map_all_indexers(t_stack *stack);
void	ft_lst_map_position(t_stack *stack);
void	ft_lst_map_weight(t_stack **stack);

bool	ft_is_sorted(t_stack *stack);
/* sorting validation functions */

void	ft_do_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_sort_2_nbrs(t_stack **stack);
t_stack	*ft_sort_3_nbrs(t_stack **stack);
/* sorting functions */

void	ft_do_swap_a(t_stack **stack);
void	ft_do_swap_b(t_stack **stack);
void	ft_do_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_do_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_do_push_b(t_stack *stack_a, t_stack *stack_b);
void	ft_do_rotate_a(t_stack **stack);
void	ft_do_rotate_b(t_stack **stack);
void	ft_do_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_do_reverse_rotate_a(t_stack **stack);
void	ft_do_reverse_rotate_b(t_stack **stack);
void	ft_do_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
/* functions that call sorting and print the action on STDOUT */

#endif
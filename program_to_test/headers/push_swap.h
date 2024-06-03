/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/29 17:06:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/includes/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_lst_init(int value);
t_stack	*ft_lst_goto_end(t_stack *list);
t_stack	*ft_lst_goto_head(t_stack *list);
t_stack	*ft_lst_goto_before_end(t_stack *list);
t_stack	*ft_lst_addto_end(t_stack *list, t_stack *new);
t_stack	*ft_lst_addto_begin(t_stack *list, t_stack *new);
t_stack	*ft_lst_delat_begin(t_stack *list);
t_stack	*ft_lst_delat_end(t_stack *list);
void	ft_lstclear_double_ptr(t_stack **list);
void	ft_lstclear_single_ptr(t_stack *list);
void	ft_lst_printf_int_content(char *msg, t_stack *list);
bool	ft_is_sign(int c);
bool	ft_is_space(int c);
t_stack	*ft_lts_buildstack_argv(t_stack *stack, char **argv);
/* new functions for push to be added in LIBFT */

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
/* validation functions */

#endif
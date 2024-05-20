/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 15:15:05 by umeneses         ###   ########.fr       */
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

t_stack	*ft_lstend_int(t_stack *list, int value);
t_stack	*ft_lst_init(int value);
/* new functions for psuh to be added in LIBFT */

void	ft_swap(t_stack **stack);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack);
void	ft_double_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	ft_double_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
/* initial push_swap functions */

bool	is_sorted(t_stack *stack);
/* validation functions */

int	push_add(int a, int b);
int push_subtract(int a, int b);
/* tester functions */

#endif
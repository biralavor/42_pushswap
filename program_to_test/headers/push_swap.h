/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 12:50:12 by umeneses         ###   ########.fr       */
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
/* new functions for psuh to be added in LIBFT */

void	swap(t_stack **stack);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack);
void	double_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	double_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
/* initial push_swap functions */

bool	is_sorted(t_stack *stack);
/* validation functions */

int	push_add(int a, int b);
int push_subtract(int a, int b);
/* tester functions */

#endif
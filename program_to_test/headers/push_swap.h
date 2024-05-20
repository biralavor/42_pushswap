/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/20 12:47:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/includes/libft.h"
# include <stdbool.h>

typedef struct s_stack_a
{
	int					nbr;
	struct s_stack_a	*prev;
	struct s_stack_a	*next;
}						t_stack_a;

typedef struct s_stack_b
{
	int				nbr;
	struct stack_b	*prev;
	struct stack_b	*next;
}					t_stack_b;

t_stack_a	*ft_lstend_int(t_stack_a *list, int value);
/* new functions for psuh to be added in LIBFT */

void	swap_a(t_stack_a **stack_a);

void	swap_ab(t_stack_a **stack_a, t_stack_b **stack_b);
void	push_a(t_stack_a **stack_a, t_stack_b **stack_b);
void	rotate_a(t_stack_a **stack_a);
void	double_rotate_ab(t_stack_a **stack_a, t_stack_b **stack_b);
void	reverse_rotate_a(t_stack_a **stack_a);
void	double_reverse_rotate_ab(t_stack_a **stack_a, t_stack_b **stack_b);
/* initial push_swap functions */

bool	is_sorted(t_stack_a *stack_a);
/* validation functions */

int	push_add(int a, int b);
int push_subtract(int a, int b);
/* tester functions */

#endif
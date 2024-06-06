/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:34:31 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/05 12:07:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*list;

	if (argc <= 2)
	{
		ft_error_msg("Not enough arguments. Please provide at leats 2 numbers");
	}
	list = NULL;
	list = ft_lts_buildstack_argv(list, argv);
	ft_lst_printf_int_content("testing main list content:", list);
	ft_printf("testing main list size: %d\n", ft_lstsize_int((t_list *)list));
	if (!ft_is_sorted(list))
	{
		if (ft_lstsize_int((t_list *)list) == 2)
			ft_sort_2_nbrs(&list);
		if (ft_lstsize_int((t_list *)list) == 3)
			ft_sort_3_nbrs(&list);
		ft_lst_printf_int_content("updated main list content:", list);
	}
	ft_lstclear_single_ptr(list);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minunit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:21:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 12:21:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "push_swap.h"

int	ft_minunit_array_counter(char **array)
{
	int arr_size;

	arr_size = 0;
	while (array[arr_size] != NULL)
	{
		arr_size++;
		if (array[arr_size] == NULL)
		{
			arr_size--;
			break ;
		}
	}
	return (arr_size);
}

void	ft_array_clear(char **array, int arr_size)
{
	while (arr_size >= 0)
	{
		free(array[arr_size]);
		arr_size--;
	}
	free(array);
}

void	ft_array_printer(char **array, int arr_size)
{
	int index;

	index = arr_size;
	while (index >= 0)
	{
		ft_printf("argv_simulation = %s\n", (array[index]));
		index--;
	}
}

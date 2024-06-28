/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:57:05 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/04 16:31:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minunit_utils.h"

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

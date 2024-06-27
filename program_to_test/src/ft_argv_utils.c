/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/27 14:33:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sign(int c)
{
	if (c == '-' || c == '+')
		return (true);
	return (false);
}

bool	ft_is_space(int c)
{
	if (c == ' ')
		return (true);
	return (false);
}

long int	ft_atoi_long_int(const char *str)
{
	long int	result;
	int			signal;
	char		*string;

	signal = 1;
	string = (char *)str;
	while (((*string >= 9 && *string <= 13) || *string == 32))
		string++;
	while ((*string == '-') || (*string == '+'))
	{
		if (*(string + 1) == '-' || *(string + 1) == '+')
			return (0);
		if (*string == '-')
			signal = signal * -1;
		string++;
	}
	result = 0;
	while (*string >= '0' && *string <= '9')
	{
		result = (result * 10) + (*string - '0');
		string++;
	}
	return (result * signal);
}

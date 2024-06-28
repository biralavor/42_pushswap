/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:43:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/28 19:05:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_argv_valid_sign_and_not_alpha(char **argv)
{
	int	index;

	index = 0;
	while (argv[++index] != NULL)
	{
		if (ft_isalpha(*(argv[index])))
			return (false);
		if (ft_is_sign(*(argv[index])) || ft_is_space(*(argv[index])))
		{
			if (ft_is_sign(*(argv[index] + 1))
				|| !ft_isdigit(*(argv[index] + 1)))
				return (false);
		}
	}
	return (true);
}

bool	ft_argv_only_nbrs_per_string(char **argv)
{
	int	index;
	int	c_counter;

	index = 0;
	while (argv[++index] != NULL)
	{
		if (ft_is_sign(*(argv[index])) || ft_is_space(*(argv[index])))
			continue ;
		if (ft_isdigit(*(argv[index])))
		{
			c_counter = 0;
			while (argv[index] && ft_isdigit(*(argv[index])))
			{
				if (ft_is_space(*(argv[index] + c_counter))
					|| (*(argv[index] + c_counter) == '\0'))
					return (true);
				if (!ft_isdigit(*(argv[index] + c_counter)))
					return (false);
				c_counter++;
			}
		}
	}
	return (false);
}

bool	ft_argv_inside_range_intmin_intmax(char **argv)
{
	long int	index;
	long int	long_nbr;
	char		*long_nbr_as_str;

	index = 0;
	while (argv[++index] != NULL)
	{
		long_nbr = ft_atoi_long_int(argv[index]);
		long_nbr_as_str = ft_itoa(long_nbr);
		if (ft_strlen(argv[index]) != ft_strlen(long_nbr_as_str))
			return (false);
		if (long_nbr < INT_MIN || long_nbr > INT_MAX)
			return (false);
	}
	return (true);
}

bool	ft_argv_is_not_duplicated(char **argv)
{
	int		after_atoi;
	int		index;
	int		future_pos;
	char	**compare;

	after_atoi = 0;
	index = 0;
	compare = argv;
	while ((argv[++index] != NULL) && (index <= ft_argv_size(argv)))
	{
		after_atoi = ft_atoi(argv[index]);
		future_pos = 1;
		while ((++future_pos <= ft_argv_size(argv)) && (future_pos != index)
			&& compare[future_pos] != NULL)
		{
			if (ft_atoi(compare[future_pos]) == after_atoi)
				return (false);
		}
	}
	return (true);
}

bool	ft_argv_validation(char **argv)
{
	if (!ft_argv_valid_sign_and_not_alpha(argv))
	{
		ft_error_msg("2..User's input must be numbers only\n");
		return (false);
	}
	if (!ft_argv_only_nbrs_per_string(argv))
	{
		ft_error_msg("3.User's input must be numbers only\n");
		return (false);
	}
	if (!ft_argv_inside_range_intmin_intmax(argv))
	{
		ft_error_msg("4.User's input is outside limits of 32-bit system\n");
		return (false);
	}
	if (!ft_argv_is_not_duplicated(argv))
	{
		ft_error_msg("5.Duplicated items detected!\n");
		return (false);
	}
	return (true);
}

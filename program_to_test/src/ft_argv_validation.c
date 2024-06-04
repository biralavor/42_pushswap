/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:43:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/04 10:33:28 by umeneses         ###   ########.fr       */
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

int	ft_argv_size(char **argv)
{
	int	size;

	size = 0;
	while (argv[++size] != NULL)
	{
		if (ft_is_sign(*argv[size]) || ft_is_space(*argv[size]))
			size++;
	}
	return (size - 1);
}

bool	ft_argv_is_duplicated(char **argv)
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
		while ((++future_pos <= ft_argv_size(argv)) && (future_pos != index))
		{
			if (ft_atoi(compare[future_pos]) == after_atoi)
				return (true);
		}
	}
	return (false);
}

bool	ft_argv_validation(char **argv)
{
	int	index;

	index = 0;
	while (argv[++index] != NULL)
	{
		if (ft_is_sign(*argv[index]) || ft_is_space(*argv[index]))
			index++;
		if (!ft_isdigit(*argv[index]))
		{
			ft_error_msg("User's input must be numbers only\n");
			return (false);
		}
	}
	if (ft_argv_is_duplicated(argv))
	{
		ft_error_msg("Duplicated items detected!\n");
		return (false);
	}
	return (true);
}

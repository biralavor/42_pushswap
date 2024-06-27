/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/26 15:35:26 by umeneses         ###   ########.fr       */
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

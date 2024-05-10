/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/10 13:09:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../src/main.c"

void test_add()
{
	assert(add(5, 3) == 8);
	ft_printf("add function test passed\n");
}

void test_subtract()
{
	assert(subtract(5, 3) == 2);
	ft_printf("subtract function test passed\n");
}

int main()
{
	test_add();
	test_subtract();
	return 0;
}

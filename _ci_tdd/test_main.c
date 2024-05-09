/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:06:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/09 19:07:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asset.h>
#include "../src/main.c"

void test_add() {
	assert(add(5, 3) == 8);
	printf("add function test passed\n");
}

void test_subtract() {
	assert(subtract(5, 3) == 2);
	printf("subtract function test passed\n");
}

int main() {
	test_add();
	test_subtract();
	return 0;
}

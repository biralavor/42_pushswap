#include "push_swap.h"

#include <stdio.h>

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*aux;

	(void)a;
	aux = a;
	fprintf(stderr, "\n\n");
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack a: |\n");
	fprintf(stderr, "|-------|--|-----------|---------------|--------|--------|----------------|\n");
	fprintf(stderr, "| value | sorted index | current index | cost_a | cost_b |      next      |\n");
	fprintf(stderr, "|-------|--------------|---------------|--------|--------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %13d | %6d | %6d | %14p |\n", aux->nbr, aux->final_pos, aux->origin, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|---------------|--------|--------|----------------|\n\n");
	aux = b;
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack b: |\n");
	fprintf(stderr, "|-------|--|-----------|---------------|--------|--------|----------------|\n");
	fprintf(stderr, "| value | sorted index | current index | cost_a | cost_b |      next      |\n");
	fprintf(stderr, "|-------|--------------|---------------|--------|--------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %13d | %6d | %6d | %14p |\n", aux->nbr, aux->final_pos, aux->origin, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|---------------|--------|--------|----------------|\n");
	fflush(stderr);
}
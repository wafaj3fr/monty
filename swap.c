#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @head: head node
 * @counter: line_number
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int l = 0, x;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	x = h->n;
	h->n = h->next->n;
	h->next->n = x;
}

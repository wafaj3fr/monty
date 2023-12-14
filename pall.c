#include "monty.h"
/**
 * pall - prints all the stack
 * @head: head node
 * @counter: line number
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

#include "monty.h"

/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, au;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(buss.file);
		free(buss.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	au = h->n;
	h->n = h->next->n;
	h->next->n = au;
}

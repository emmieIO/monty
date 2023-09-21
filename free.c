#include "main.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *init;

	init = head;
	while (head)
	{
		init = head->next;
		free(head);
		head = init;
	}
}

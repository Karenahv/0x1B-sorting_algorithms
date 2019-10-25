#include "sort.h"


/**
 * insertion_sort_list - sort and array
 * @list: head of the double linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tempnext = NULL;
	listint_t *temprev = NULL;
	listint_t *temp = NULL;
	listint_t *temp2 = NULL;

	temp = *list;
	while (temp->next != NULL)
	{
		tempnext = temp->next;
		temprev = temp;
		temp2 = temp;
		if (temprev->n > tempnext->n)
		{
			if (temprev->prev == NULL && tempnext != NULL)
			{
				temprev->next = tempnext->next;
				temprev->prev = tempnext;
				tempnext->prev = NULL;
				tempnext->next = temprev;
				print_list(*list);
			}
			else if (temprev->prev == NULL && tempnext == NULL)
			{
				temprev->prev = tempnext;
				temprev->next = NULL;
				tempnext->prev = NULL;
				tempnext->next = temprev;
				print_list(*list);
			}
			else
			{
				while (temp2->prev != NULL)
				{
					tempnext = temp2->next;
					temprev = temp2;
					if (temprev->n > tempnext->n)
					{
						if (temprev->prev)
							temprev->prev->next = tempnext;
						if (tempnext->next)
							tempnext->next->prev = temprev;
						temprev->next = tempnext->next;
						tempnext->next = temprev->prev;
						temprev->prev = tempnext;
						tempnext->next = temprev;
						print_list(*list);
					}
					temp2 = temp2->prev;
				}
			}
		}
		temp = temp->next;
	}
}

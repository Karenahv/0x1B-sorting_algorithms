#include "sort.h"


/**
 * insertion_sort_list - sort and array
 * @list: head of the double linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tnext = NULL;
	listint_t *tprev = NULL;
	listint_t *temp2 = NULL;
	int count = 0, flag = 0;

	if (!*list || !list || !(*list)->next)
		return;
	tnext = (*list)->next;
	tprev = *list;
	temp2 = *list;
	while (tnext->next != NULL)
	{
		if (count == 0)
		{
			if (tprev->n > tnext->n)
			{
				tnext->next->prev = tprev;
				tprev->next = tnext->next;
				tprev->prev = tnext;
				tnext->next = tprev;
				tnext->prev = NULL;
				print_list(*list);
			}
		}
		while (tprev->prev != NULL)
		{
		        if (tprev->n > tnext->n && flag == 0)
			{
				temp2 = tprev;
				if (tprev->prev)
					tprev->prev->next = tnext;
				if (tnext->next)
					tnext->next->prev = tprev;
				tprev->next = tnext->next;
				tnext->prev = tprev->prev;
				tprev->prev = tnext;
				tnext->next = tprev;
				if (!tnext->prev)
				{
					*list = tnext;
					print_list(*list);
					break;
				}
				print_list(*list);
				tnext = tnext->prev;
				tprev = tprev->prev;
				flag = 1;
			}else
				break;
			if (tnext->n > tprev->n && flag == 1)
			{
				if (tnext->prev)
					tnext->prev->next = tprev;
				if (tprev->next)
					tprev->next->prev = tnext;
				tnext->next = tprev->next;
				tprev->prev = tnext->prev;
				tnext->prev = tprev;
				tprev->next = tnext;
				if (!tprev->prev)
				{
					*list = tprev;
					print_list(*list);
					break;
				}
				print_list(*list);
				tprev = tprev->prev;
				tnext = tnext->prev;
				flag = 0;
			}else
				break;
		}
		temp2 = temp2->next;
		tnext = temp2;
		tprev = temp2->prev;
		count = count + 1;
		flag = 0;
	}
}

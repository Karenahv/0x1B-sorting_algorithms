#include "sort.h"

/**
 * swap_from_right - swap items of a list from right
 * @i: current item address
 * @list: list
 *
 * Return: void
 */
void swap_from_right(listint_t **i, listint_t **list)
{
	i = (&(*i)->prev);

	while ((*i)->prev)
	{
		listint_t **b = &(*i)->next;
		listint_t **a = i;

		listint_t *next_b = (*b)->next;
		listint_t *next_a = (*a)->next;
		listint_t *prev_a = (*a)->prev;

		if ((*a)->n > (*b)->n)
		{
			prev_a->next = *b;
			(*b)->next = *a;
			next_a->prev = *b;
			(*b)->prev = prev_a;
			(*a)->next = next_b;
			print_list(*list);
		}

		*i = *(&(*i)->prev);
	}
}

/**
 * swap - swap items of a list
 * @list: list to change
 *
 * Return:_ void
 */
void swap(listint_t **list)
{
	listint_t **i = list;

	while ((*i)->next)
	{
		if ((*i)->n > (*i)->next->n)
		{
			listint_t *next_b = (*i)->next->next;
			listint_t *prev_a = (*i)->prev;

			listint_t *tmp = *i;
			*i = (*i)->next;
			*(&(*i)->next) = tmp;

			(*i)->next->next = next_b;
			(*i)->next->prev = *i;
			(*i)->prev = prev_a;
			print_list(*list);
		}

		i = (&(*i)->next);
	}

	swap_from_right(i, list);
}

/**
 * cocktail_sort_list - sort list by cocktail sort method
 * @list: list to change
 *
 * Rerturn: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp_loop = NULL;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	tmp_loop = *list;

	while (tmp_loop)
	{
		swap(list);
		tmp_loop = tmp_loop->next;
	}
}

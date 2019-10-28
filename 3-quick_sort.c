#include "sort.h"

/**
 * swap - swap items
 * @a: item 1
 * @b: item 2
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - search pivot and swap items
 * @array: The array to be printed
 * @lo: left position init
 * @hi: right position
 * @size: Number of elements in @array
 *
 * Return: pivot number
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int j = lo, i;

	for (i = lo; i < hi; i++)
	{
		if (array[i] < pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}

			j += 1;
		}
	}

	if (hi != j)
	{
		swap(&array[hi], &array[j]);
		print_array(array, size);
	}

	return (j);
}

/**
 * quicksort - quick sort function with more parameters
 * @array: The array to be printed
 * @lo: left position init
 * @hi: right position
 * @size: Number of elements in @array
 *
 * Return: void
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int pivot = partition(array, lo, hi, size);

		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - quick sort function
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void quick_sort(int *array, int size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

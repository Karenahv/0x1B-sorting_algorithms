#include "sort.h"

/**
 * merge_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void top_down_merge(int *copy, int begin, int middle, int end, int *array)
{

	int i, j, k;

	i = begin;
	j = end;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, middle - begin);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	for (k = begin; k < end; k++)
	{
		if(i < middle && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i = i + 1;
		}else
		{
			copy[k] = array[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(copy + begin, end - begin);
}

/**
 * merge_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void top_down_split_merge(int *copy, int begin, int end, int *array)
{

	int middle = 0;

	if (end - begin < 2)
		return;
	middle = (end + begin)/2;
	top_down_split_merge(copy, begin, middle, array);
	top_down_split_merge(copy, middle, end, array);
	top_down_merge(copy, begin, middle, end, array);

}

/**
 * merge_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int end = 0;
	int *copy = NULL;
	size_t k = 0;

	if (!array || !size || size <= 1)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	end = size;
	for (k = 0; k < size; k++)
		copy[k] = array[k];
	top_down_split_merge(copy, 0, end, array);
	free(copy);
}

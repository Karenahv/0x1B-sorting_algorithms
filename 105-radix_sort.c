#include "sort.h"

/**
 * radix_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void radix_sort(int *array, size_t size)
{

	int max = 0, num = 10;
	size_t i, digits = 0;
	int *array2, *new_array, *temp, *temp2;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max > 0)
	{
		max = max / num;
		digits++;
	}
	array2 = array;
	new_array = malloc(sizeof(int) * size);
	temp = new_array;
	for (i = 0; i < digits; i++)
	{

		get_digits_radix(array2, size, i, new_array);
		temp2 = array2;
		array2 = new_array;
		new_array = temp2;
		print_array(array2, size);
	}
	for (i = 0; i < size; i++)
		array[i] = array2[i];
	free(temp);
}



/**
 * get_digits_radix - sort and array
 * @array2: pointer to the array
 * @size: size of the array
 * @count: position of digit to obtain
 * @new_array: copy array
 * Return: no return
 */
int get_digits_radix(int *array2, size_t size, int count, int *new_array)
{
	size_t i;
	int digit = 0, j = 0;
	int index[10];

	for (i = 0; i < 10; i++)
		index[i] = 0;
	for (i = 0; i < size; i++)
	{
		digit = obtain_digit(array2[i], count);
		index[digit] = index[digit] + 1;
	}
	for (i = 1; i < size + 1; i++)
		index[i] = index[i] + index[i - 1];
	for (j = size - 1; j > -1; j--)
	{
		new_array[index[obtain_digit(array2[j], count)]-- - 1] = array2[j];
	}
	return (1);

}

/**
 * obtain_digit - sort and array
 * @num: number
 * @count: position we are trying to extract
 * Return: no return
 */
int obtain_digit(long num, int count)
{


	long i = 0L, pow = 1L, r;

	for (i = 0; i < count; i++)
		pow = pow * 10L;
	r = ((num / pow) % 10);
	return (r);

}

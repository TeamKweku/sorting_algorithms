#include "sort.h"

/**
 * swap - function that swaps two values
 * @xp: pointer to x
 * @yp: pointer to y
 *
 * Return: nothing
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - function to sort an array in
 * in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
}

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
 * selection_sort - function that sorts an array of integers
 * in ascending order using selection sort method
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 *  Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

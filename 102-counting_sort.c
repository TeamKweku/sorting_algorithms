#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in
 * ascending order accoring the counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int k = 0;
	int *count, *sorted;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = malloc((k + 1) * sizeof(int));
	if (!count)
		return;

	for (i = 0; i <= (size_t)k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)k; i++)
		count[i] += count[i - 1];

	sorted = malloc(size * sizeof(int));
	if (!sorted)
	{
		free(count);
		return;
	}
	for (i = size - 1; i < size; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	print_array((const int *)count, k + 1);

	free(count);
	free(sorted);
}

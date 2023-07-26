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
	int i, k = 0, n = size;
	int *count, *sorted;

	if (!array || size < 2)
		return;
	for (i = 0; i < n; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc((k + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		++count[array[i]];
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array((const int *)count, k + 1);

	sorted = malloc(size * sizeof(int));
	if (!sorted)
	{
		free(count);
		return;
	}
	for (i = n - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < n; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}

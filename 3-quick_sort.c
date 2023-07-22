#include "sort.h"
/**
 * lamuto - function to partion an array for the quicksort
 * algorithm using the lamuto partition scheme
 *
 * @array: array to be partitioned
 * @low: lower bound
 * @high: upper bound
 * @size: size of the array
 *
 * Return: the index of pivot
 */
size_t lamuto(int *array, ssize_t low, ssize_t high, size_t size)
{
	int swap, pivot;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - function that sorts an array of integers in
 * ascending order using quicksort algorithm with the
 * lamuto partition scheme
 *
 * @array: array to be sorted
 * @low: lower bound
 * @high: high bound
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pi;

	if (low < high)
	{
		pi = lamuto(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - function sorts an integer of arrays in
 * ascending order using the quicksort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

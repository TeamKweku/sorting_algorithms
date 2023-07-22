#include "sort.h"

/**
 * knuth_sequence - calculates the interval to be used for the
 * shell sort algorithm by using Knuth Sequence
 *
 * @size: size of the array
 *
 * Return: interval based on the size of array
 */
size_t knuth_sequence(size_t size)
{
	size_t h = 1;

	while (h <= size)
		h = h * 3 + 1;
	return (h / 3);
}

/**
 * insertion_sort - implementation of insertion sort algorithm
 * using the knuth sequence return as a step for insertion
 *
 * @array: array to be sorted
 * @size: size of the array
 * @step: knuth sequence interval
 *
 * Return: nothing
 */
void insertion_sort(int array[], size_t size, size_t step)
{
	size_t i;
	int j, temp;

	for (i = step; i < size; i++)
	{
		temp = array[i];
		j = i - step;

		while (j >= 0 && array[j] > temp)
		{
			array[j + step] = array[j];
			j -= step;
		}

		array[j + step] = temp;
	}
}

/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int array[], size_t size)
{
	size_t step = knuth_sequence(size);

	while (step > 0)
	{
		insertion_sort(array, size, step);
		print_array(array, size);
		step = (step - 1) / 3;
	}
}

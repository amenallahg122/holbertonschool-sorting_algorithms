#include "sort.h"
/**
 * swap - Swaps the values of two integers.
 * @i: Pointer to the first integer.
 * @j: Pointer to the second integer.
 *
 * This function takes two integer pointers as input and swaps
 * the values they point to.
 */
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * partition - Partitions the array and returns the pivot index.
 * @array: The array to be partitioned.
 * @low: The starting index of the array or subarray.
 * @high: The ending index of the array or subarray.
 * @size: The size of the array.
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= array[high])
		{
			i++;
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
		return (i + 1);
}
/**
 * quick_sort_recursion - Recursively sorts an array
 * using Quick Sort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index of the array or subarray.
 * @high: The ending index of the array or subarray.
 * @size: The size of the array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low >= high)
		return;
	pivot_index = partition(array, low, high, size);
	quick_sort_recursion(array, low, pivot_index - 1, size);
	quick_sort_recursion(array, pivot_index + 1, high, size);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}

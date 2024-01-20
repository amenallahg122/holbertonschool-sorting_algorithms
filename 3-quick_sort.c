#include "sort.h"
/**
 * swap - Swaps two integers in an array
 * @val1: Pointer to the first integer
 * @val2: Pointer to the second integer
 */
void swap(int *val1, int *val2)
{
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}
/**
 * partition - Partitions the array using the Lomuto partition scheme
 * @array: Pointer to the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * @size: Size of the array
 * Return: The index of the pivot
 */
int partition(int *array, size_t left, size_t right, size_t size)
{
	int pivot = array[right];
	size_t j, i = left - 1;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[right]);
	print_array(array, size);
	return (i + 1);
}
/**
 * Sorting - Recursive function for Quick Sort
 * @array: Pointer to the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * @size: Size of the array
 */
void Sorting(int *array, size_t left, size_t right, size_t size)
{
	size_t index;

	if (left < right)
	{
		index = partition(array, left, right, size);
		Sorting(array, left, index - 1, size);
		Sorting(array, index + 1, right, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm with Lomuto partition scheme
 * @array: Pointer to the array
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	Sorting(array, 0, size - 1, size);
}

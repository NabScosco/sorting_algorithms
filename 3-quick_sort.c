#include "sort.h"

/**
 * lomuto_partition - Partitions an array using Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @low: The lower bound of the array.
 * @high: The upper bound of the array.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quicksort(array, 0, size - 1, size);
}

#include "sort.h"
/**
 * swap - function that swaps two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - function that partitions the array using the Lomuto
 * partition scheme
 * @array: the array to partition
 * @low: the low index
 * @high: the high index
 * @size: the size of the array
 *
 * Return: the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - recursive function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to sort
 * @low: the low index
 * @high: the high index
 * @size: the size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
		int pivot;

		if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

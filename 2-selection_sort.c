#include "sort.h"
/**
 * swap - swaps two different array elements
 * @x: first element
 * @y: second element
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, idx;

	if (!array || size == 0 || size == 1)
		return;
	
	/* Loop over array and shift boundary of sorted subarray */
	for (i = 0; i < size - 1; i++)
	{
		/* Find minimum element in unsorted sub-array */
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}

		/* Swap min element with first element of sub-array */
		if (idx != i)
		{
			swap(&array[idx], &array[i]);
			print_array(array, size);
		}
	}
}

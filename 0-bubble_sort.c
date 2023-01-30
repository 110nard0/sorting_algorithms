#include "sort.h"
/**
 * swap - swaps two different integer values
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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of integer elements in array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (!array || size == 0 || size == 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

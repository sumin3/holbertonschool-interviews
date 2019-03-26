#include "search_algos.h"
void print_array(int *array, size_t size);
/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return:  return the index where value is located. Otherwise, return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid = size / 2;

	print_array(array,  size);
	if (!array)
		return (-1);
	else if (array[mid] == value)
		return (mid);
	else if (array[mid] > value && size >= 2)
		return (binary_search(array, size - mid, value));
	else if (array[mid] < value && size >= 2)
	{
		if (size % 2 != 0)
			return (binary_search(array + mid + 1, size - mid - 1, value));
		return (binary_search(array + mid, size - mid, value));
	}
	else
		return (-1);
}
/**
 * print_array - print array
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	if (array  && size != 0)
	{
		printf("Searching in array: ");
		for (i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			if (i != size - 1)
				printf(", ");
		}
		printf("\n");
	}
}

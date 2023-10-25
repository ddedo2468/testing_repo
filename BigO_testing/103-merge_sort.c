#include "sort.h"
/**
 * merge_subarr - Sort a subarray of integers.
 * @a: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @start: The front index of the array.
 * @mid: The middle index of the array.
 * @end: The back index of the array.
 */

void merge_subarr(int *a, int *buff, size_t start, size_t mid, size_t end)
{
	size_t i = start;
	size_t j = mid + 1, k = 0;

	printf("Merging...\n[left]: ");
	print_array(a + start, mid - start + 1);
	printf("[right]: ");
	print_array(a + mid, end - mid);
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			buff[k] = a[i];
			i++;
		}
		else
		{
			buff[k] = a[j];
			j++;
		}
		k++;
	}
	while (j <= end)
	{
		buff[k] = a[j];
		j++;
		k++;
	}
	while (i <= mid)
	{
		buff[k] = a[i];
		i++;
		k++;
	}
	for (k = start; k <= end; k++)
		a[k] = buff[k - start];
	printf("[Done]: ");
	print_array(a + start, end - start + 1);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @a: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @start: The front index of the subarray.
 * @end: The back index of the subarray.
 */

void merge_sort_recursive(int *a, int *buff, size_t start, size_t end)
{
	size_t mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort_recursive(a, buff, start, mid);
		merge_sort_recursive(a, buff, mid + 1, end);
		merge_subarr(a, buff, start, mid, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size - 1);

	free(buff);
}

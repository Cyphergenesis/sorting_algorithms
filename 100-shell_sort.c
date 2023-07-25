#include "sort.h"
/**
* swap_ints - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
	int tm_p;
	tm_p = *a;
	*a = *b;
	*b = tm_p;
}
/**
* shell_sort - Sort an array of integers in ascending
* order using the shell sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Uses the Knuth interval sequence.
*/
void shell_sort(int *array, size_t size)
{
	size_t gaps, i, k;
	if (array == NULL || size < 2)
		return;
	for (gaps = 1; gaps < (size / 3);)
		gaps = gaps * 3 + 1;
	for (; gaps >= 1; gaps /= 3)
	{
		for (i = gaps; i < size; i++)
			{
				k = i;
				while (k >= gaps && array[k - gaps] > array[k])
					{
						swap_ints(array + k, array + (k - gaps));
						k -= gaps;
					}
			}
		print_array(array, size);
	}
}

#include "sort.h"
/**
 * quick_sort - sorts an array using the quicksort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2) 
        return; /*base case*/

    lo_sort(array, size, 0, size - 1); /*perform quicksort*/
}

/**
 * lo_partition - order a subset of an array according to the lomuto partition sche
 * @array: array to sort
 * @size: size of the array
 * @low: start index
 * @high: end index
 * Return: the partition index
*/
int lo_partition(int *array, size_t size, int low, int high)
{
    int *pivot, above, below;

    pivot = array + high; /*pivot element*/
    for (above = below = low; below < high; below++)
    {
        if (array[below] < *pivot) /*compare array elements with pivot*/
        {
            if (above < below)
            {
                swap(array + below, array + above); /*swap if less than*/
                print_array(array, size); /*print array after swap*/
            }
            above++;
        }
    }
    if (array[above] > *pivot) /*checking if pivot is in correct position...*/
    {
        swap(array + above, pivot); /*swap if not*/
        print_array(array, size); /*print after the swap*/
    }
    return (above); /*return partition index*/
}

/**
 * lo_sort - implement quick sort 
 * @array: the array to sort
 * @size: size of the array
 * @high: end index
 * @low: start index
*/

void lo_sort(int *array, size_t size, int low, int high)
{
    int part;

    if (high - low > 0) /*base case*/
    {
        part = lo_partition(array, size, low, high); /*partition the array*/
        lo_sort(array, size, low, part - 1); /*recursively sort left half*/
        lo_sort(array, size, part + 1, high);/*sort right half*/
    }
}

/**
 * swap - swaps two indexes on the array
 * @a: first index
 * @b: second index
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

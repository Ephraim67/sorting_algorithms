#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * @array: A pointer to an integer array.
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp, flag;

    /*an array of less than 2 is already sorted.*/
    if (size < 2 || array == NULL)
        return;
    for (i = 0; i < size - 1; i++)
    {
        flag = 0;
        /*loops to j < size - i - 1 to avoid redundancy, passing only through the unsorted part of the array and leaving the sorted part be. size - i - 1 reps the unsorted elements in the array after 'i' iterations of the outer loop*/
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1; /*indicates a swap was made*/
                print_array(array, size);
            }
        }
         /*if no swap was made, array is already sorted*/
        if (flag == 0)
        {
            break;
        }
    }
}
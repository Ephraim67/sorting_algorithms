#include "sort.h"
/**
 * selection_sort - function to implement the selection sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
    size_t i, j, iMin;
    int temp;

    /*an array of size two is already sorted*/
    if (size < 2 || array == NULL){
        return;
    }
    for (i = 0; i < size - 1; i++)
    {
        iMin = i;
        /*get the index of the minimum element of the unsorted array*/
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[iMin])
            {
                iMin = j;
            } 
        }
        /*swap the minimum with the first element in the unsorted array*/
        if (iMin != i)
        {
            temp = array[i];
            array[i] = array[iMin];
            array[iMin] = temp;
        }
        /*print the array after each swap*/
        print_array(array, size);
    }
}

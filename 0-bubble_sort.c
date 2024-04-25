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

int main(void)
{
    int array[] = {84, 27, 63, 18, 50, 72, 91, 33, 46, 12, 65, 38, 54, 79, 23, 96, 7, 42, 58, 21, 95, 30, 69, 14, 82, 36, 60, 25, 87, 3, 68, 49, 17, 74, 9, 45, 78, 15, 56, 39, 81, 6, 71, 20, 92, 48, 1, 26, 99};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
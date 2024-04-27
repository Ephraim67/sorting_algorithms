#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *temp, *swap; /*temp will be used for traversing and swap is used for swapping elements*/

        if (list == NULL || *list == NULL || (*list)->next == NULL) /*check if list is Null or if it has less than 2 elements*/
                return;
        temp = (*list)->next; /*initialize temp wit the second element in the list*/
        while (temp != NULL)
        {
                while(temp->prev && temp->prev->n > temp->n) /*check if need to swap*/
                {
                        swap = temp->prev;
                        if (swap->prev != NULL)
                        {
                                /*ensure the list remains connected after the swap*/
                                swap->prev->next = temp;
                        }
                        swap->next = temp->next; /*move temp forward*/
                        if (swap->next != NULL)
                        {
                                swap->next->prev = swap;
                        }
                        /*swapping..*/
                        temp->prev = swap->prev;
                        temp->next = swap;
                        swap->prev = temp;
                        if (temp->prev == NULL)
                        {
                                *list = temp; /*if temp is now the first node, update the head ofthe lis to point to temp*/
                        }
                        print_list((const listint_t *)*list);/*print current state of list after each individual swap*/
                }
                temp = temp->next; /*move temp to the next node in the list*/
        }
}
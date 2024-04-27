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


listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
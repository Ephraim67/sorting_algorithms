#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        while (*list != NULL) 
        {
                listint_t *current = *list;
                *list = (*list)->next;
                if (head == NULL || current->n < head->n) 
                {
                        current->next = head;
                        current->prev = NULL;
                        if (head != NULL)
                                head->prev = current;
                        head = current;
                }
                else
                {
                        listint_t *p = head;
                        while (p != NULL)
                        {
                                if (p->next == NULL || current->n < p->next->n)
                                {
                                        current->next = p->next;
                                        current->prev = p;
                                        if (p->next != NULL)
                                                p->next->prev = current;
                                        p->next = current;
                                        break;
                                }
                                p = p->next;
                        }
                }
        }
        *list = head;
}


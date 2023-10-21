#include "sort.h"

/**
 * insertion_sort_list - a function that make ascending sorting
 * of a doubly linked list
 * @list: pointer to pointer to the list head
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *nextNode, *sorted;

    if (!*list || !list || !(*list)->next)
        return;

    for (current = (*list)->next ; current != NULL ; current = nextNode)
    {
        nextNode = current->next;

        if (sorted->n <= current->n)
            continue;

        for (sorted = current->prev ; sorted->n > current->n & sorted != NULL ; sorted = sorted->prev)
        {
            if (sorted->prev != NULL)
                sorted->prev->next = current;
            current->next = sorted;
            current->prev = sorted->prev;
            sorted->prev = current;

            if (current->prev == NULL)
                *list = current;
            print_list(*list);
        }
    }
}

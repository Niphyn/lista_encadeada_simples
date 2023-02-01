
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *node_construct(int value, Node *next)
{
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void node_delete(Node *node)
{
    free(node);
}

LinkedList *list_construct()
{
    LinkedList *lst = (LinkedList *)calloc(1, sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    return lst;
}

void list_add_left(LinkedList *lst, int value)
{
    lst->head = node_construct(value, lst->head);
    lst->size++;
}

int list_pop_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    int head_value = lst->head->value;
    Node *previous_head = lst->head;

    lst->head = lst->head->next;
    lst->size--;

    node_delete(previous_head);

    return head_value;
}

int list_get_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    return lst->head->value;
}

void list_print(LinkedList *lst)
{
    Node *it = lst->head;

    while (it != NULL)
    {
        printf("%d ", it->value);
        it = it->next;
    }
}

void list_delete(LinkedList *lst)
{
    // do not use lst->size in the loop below becasue
    // pop_left decrease size.
    int size = lst->size;

    for (int i = 0; i < size; i++)
        list_pop_left(lst);

    free(lst);
}


#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *node_construct(void *value, Node *next)
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

LinkedList *list_construct(desaloca funcao_desalocando, comparacao funcao_comparando)
{
    LinkedList *lst = (LinkedList *)calloc(1, sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    lst->ptr_funcao_desaloca = funcao_desalocando;
    lst->ptr_funcao_comparacao = funcao_comparando;
    return lst;
}

void list_add_left(LinkedList *lst, void *value)
{
    lst->head = node_construct(value, lst->head);
    lst->size++;
}

void list_add_sorted(LinkedList *lst, void *value){

    if(lst->size < 1){
        lst->head = node_construct(value, lst->head);
    }else{

        Node *next_node,*left_node,*right_node,*new_node;
        comparacao comparando = lst->ptr_funcao_comparacao;
        
        next_node = lst->head;
        right_node = lst->head;
        left_node = NULL;

        while(next_node != NULL){
            if((comparando(next_node->value,value)) < 0){
                left_node = next_node;
                right_node = next_node->next;
            }
            next_node = next_node->next;
        }
        if(left_node == NULL){
           lst->head = node_construct(value, lst->head);
        }else{
            new_node = node_construct(value, right_node);
            left_node->next = new_node;
        }
    }

    lst->size++;
}

void list_pop_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    void *head_value = lst->head->value;
    Node *previous_head = lst->head;

    lst->head = lst->head->next;
    lst->size--;

    desaloca funcao_desaloca = lst->ptr_funcao_desaloca;
    funcao_desaloca(head_value);
    node_delete(previous_head);
}

void *list_get_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    return lst->head->value;
}

//não está adaptada para todos os tipos
void list_print(LinkedList *lst)
{
    Node *it = lst->head;

    while (it != NULL)
    {
        printf("%s ", (char *)(it->value));
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

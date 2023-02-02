
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef void (*desaloca)(const void *value);

typedef int (*comparacao)(const void *value1, const void *void2);

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
    desaloca ptr_funcao_desaloca;
    comparacao ptr_funcao_comparacao;
} LinkedList;

Node *node_construct(void *value, Node *next);
void node_delete(Node *node);

LinkedList *list_construct(desaloca funcao_desalocando, comparacao funcao_comparando);
void list_add_left(LinkedList *lst, void *value);
void list_add_sorted(LinkedList *lst, void *value);
void list_pop_left(LinkedList *lst);
void *list_get_left(LinkedList *lst);
void list_print(LinkedList *lst);
void list_delete(LinkedList *lst);

#endif

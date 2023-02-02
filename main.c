#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

void desalocando(const void *value){
    char * string = (char*)value;
    free(string);
}

int comparacao_1(const void *value1, const void *value2){
    char *string1 = (char*)value1;
    char *string2 = (char*)value2;
    return strcmp(string1,string2);
}
int main()
{
    LinkedList *lst = list_construct(desalocando,comparacao_1);

    list_add_sorted(lst, (void*)strdup("a"));
    list_add_sorted(lst, (void*)strdup("e"));
    list_add_sorted(lst, (void*)strdup("d"));
    list_add_sorted(lst, (void*)strdup("c"));
    list_add_sorted(lst, (void*)strdup("b"));

    list_print(lst);
    printf("\n");

    list_delete(lst);

    return 0;
}

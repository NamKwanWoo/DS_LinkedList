#include <stdio.h>
#include "LinkedList.h"

void TraverseList(List *list, int num)
{
    list->cur = list->head;

    if(!num)
        printf("The list in reverse is: ");

    else
        printf("The list is is: ");

    while(list->cur != NULL)
    {
        printf("%c ", list->cur->data);
        list->cur = list->cur->next;
    }
    printf("*\n\n");
}


int main(void)
{
    List list1, list2;
    int i;

    InitList(&list1);

    list2.head = NULL;
    list2.cur  = NULL;
    list2.tail = NULL;

    list1.numOfData = 0;
    list2.numOfData = 0;

    
    for(i=0; i<10 ;i++)
        insert(&list1, (char)i+65);
    
    TraverseList(&list1, TRUE);
    
    for(i=0; i<10 ;i++)
        push(&list2, pop(&list1));    
    
    TraverseList(&list2, FALSE);
}
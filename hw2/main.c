#include <stdio.h>
#include "LinkedList.h"

void TraverseList(List *list, int num)
{
    list->cur = list->head;
    
    if(!num)
        printf("The merged list is: ");    
        
    else
        printf("List %d is: ", num);
    
    while(list->cur != NULL)
    {
        printf("%d ", list->cur->data);
        list->cur = list->cur->next;
    }
    printf("*\n\n");
}

List* MergerList(List *list1, List *list2)
{
    int arr[list1->numOfData + list2->numOfData];
    int i = 0, j;
    int temp;
    int Len = sizeof(arr) / sizeof(int);
    
    list1->cur = list1->head;
    while(!IsListEmpty(list1))
        arr[i++] = DeleteData_Head(list1);
    
    list2->cur = list2->head;
    while(!IsListEmpty(list2))
        arr[i++] = DeleteData_Head(list2);
    
    
    for(i=0; i < Len-1; i++)
    {
        for(j=0; j<Len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(i=0; i<Len; i++)
        AddData_Tail(list1, arr[i]);
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
    
    for(i=1; i<=10; i++)
    {
        if(i % 2)
            AddData_Tail(&list2, i);
        else
            AddData_Tail(&list1, i);
    }
    
    TraverseList(&list1, 1);
    TraverseList(&list2, 2);
    
    MergerList(&list1, &list2);
    
    TraverseList(&list1, FALSE);
    
    return 0;
    
}
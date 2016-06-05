#include <stdio.h>
#include "LinkedList.h"

#define Selecte      printf("? ");
#define NewLine      printf("\n\n");

void PrintInterface()
{
    puts("Enter your choice");
    printf("\t 1 to push a value on the stack\n");
    printf("\t 2 to pop a value off the stack\n");
    printf("\t 3 to end program.\n");

}

void PrintProcess(List *list)
{
    list->cur = list->head;

    while (list->cur != NULL && !IsListEmpty(list))
    {
        printf("%d --> ", list->cur->data);
        list->cur = list->cur->next;
    }

    puts("NULL");
}


int main(void)
{
    List list;
    int i, nKey = TRUE;
    Data data;

    InitList(&list);
    list.numOfData = 0;
    PrintInterface();

    while (TRUE)
    {
        Selecte;

        scanf("%d", &nKey);
        getchar();

        if (nKey == 1)
        {
            printf("Enter a integer: ");
            scanf("%d", &data);
            printf("value: %c\n", data);

            push(&list, data);

            puts("The stack is: ");
            PrintProcess(&list);
        }

        else if (nKey == 2)
        {
            printf("The popped value is %d.\n", pop(&list));

            puts("The stack is: ");
            PrintProcess(&list);
        }

        else if (nKey == 3)
        {
            puts("End of run");
            nKey = FALSE;
            break;
        }

        NewLine
    }

    return 0;
}




#include <stdio.h>
#include "LinkedList.h"

#define Selecte      printf("? ");
#define NewLine      printf("\n\n");

void PrintInterface()
{
    puts("Enter your choice");
    printf("\t 1 to insert an element into the list\n");
    printf("\t 2 to delete an element from the list\n");
    printf("\t 3 to end.\n");

}

void PrintProcess(List *list)
{
    list->cur = list->head;

    while (list->cur != NULL && !IsListEmpty(list))
    {
        if(list->cur->data != NULL)
            printf("%c --> ", list->cur->data);
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
            printf("Enter a character: ");
            scanf("%c", &data);
            printf("value: %c\n", data);

            Add_alphabeticalOrder(&list, data);
            
            puts("The list is: ");
            PrintProcess(&list);
        }

        else if (nKey == 2)
        {
            printf("Enter character to be deleted: ");
            scanf("%c", &data);
            printf("value: %c\n", data);

            if(DeleteSpecData(&list, data) == '#')
            {
                printf("%c not found\n", data);
                NewLine
                continue;
            }

            puts("The list is: ");
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




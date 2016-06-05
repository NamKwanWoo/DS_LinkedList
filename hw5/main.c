#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
    List stack;
    List list;
    char *str = (char*)malloc(sizeof(char) * 100);
    int i=0, success = TRUE;
    
    InitList(&stack);
    
    list.head = NULL;
    list.cur = NULL;
    list.tail = NULL;
    
    stack.numOfData = 0;
    list.numOfData = 0;
    
    
    puts("Enter a line of text:");
    gets(str);
    
    while(*(str + i ) != '\0')
    {
        insert(&list, *(str+i));
        i++;
    }
    
    while(!IsListEmpty(&list))
        push(&stack, pop(&list));
    
    i=0;
    while(!IsListEmpty(&stack))
    {
        if(pop(&stack) != *(str + i))
        {
            success = FALSE;
            break;
        }
        i++;
    }
    
    if(success)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
    
}
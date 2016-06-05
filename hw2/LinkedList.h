//
// Created by 남관우 on 2016. 6. 4..
//

#ifndef TEST_LINKEDLIST_H
#define TEST_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE    0

typedef int Data;

typedef struct _list
{
    Data data;
    struct _list *next;
} Node;

typedef struct _linkedList
{
    Node *head;
    Node *tail;
    Node *cur;

    int numOfData;
} LinkedList;

typedef LinkedList List;

void InitList(List *);

int IsListEmpty(List *);

void AddData_Head(List *, Data data);

void AddData_Tail(List *, Data data);

Data DeleteSpecData(List *list, Data data);

Data DeleteData_Head(List *);

Data DeleteData_Tail(List *);

Data HeadData(List *);

Data TailData(List *);


#endif //TEST_LINKEDLIST_H

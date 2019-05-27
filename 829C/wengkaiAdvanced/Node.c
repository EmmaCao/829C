//
//  Node.c
//  829C
//
//  Created by Emma on 2019/5/27.
//  Copyright © 2019 Emma. All rights reserved.
//

#include "Node.h"

//List list;
//int number;
//list.head = NULL;
//do {
//    scanf("%d", &number);
//    add(&list, number);
//} while (number != -1);
void add(List *pList, int number)
{
    if (number != -1) {
        //add to linked-list
        Node *p = (Node*)malloc(sizeof(Node));
        p->value = number;
        p->next = NULL;
        //find the last
        Node *last = pList->head;
        if (last) {
            while (last->next) {
                last = last->next;
            }
            //attach
            last->next = p;
        }
        else{
            pList->head = p;
        }
    }
}

//print(&list);
void print(List *pList)
{
    Node *p;
    //经典循环：遍历链表
    for (p = pList->head; p; p=p->next) {
        printf("%d ", p->value);
    }
    printf("\n");
}

void clearList(List *pList)
{
    Node *p, *q;
    for (p = pList->head; p; p = q) {
        q = p->next;
        free(p);
    }
}

//scanf("%d", &number);
//deleteNumber(&list, number);
void deleteNumber(List *pList, int number)
{
    //how do we find the boundary?
    //Any pointer at the left of -> must be checked
    Node *q, *p;
    for (q = NULL, p = pList->head; p; q=p, p=p->next) {
        if (p->value == number) {
            if (q) {
                q->next = p->next;
            }
            else{
                pList->head = p->next;
            }
            free(p);
            break;
        }
    }
}

void search(List *pList, int number)
{
    Node *p;
    int isFound = 0;
    for (p = pList->head; p; p=p->next) {
        if (p->value == number) {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound) {
        printf("没有找到\n");
    }
}

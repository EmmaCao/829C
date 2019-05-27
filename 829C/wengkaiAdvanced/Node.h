//
//  Node.h
//  829C
//
//  Created by Emma on 2019/5/27.
//  Copyright © 2019 Emma. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int value;
    struct _node *next; //编译器在该行还不知道Node是什么，故不能用Node *next
} Node;

//定义一个自己的数据结构表示List，用于扩展升级
typedef struct _list{
    Node* head;
} List;

void add(List *pList, int number);
void print(List *pList);
void clearList(List *pList);
void deleteNumber(List *pList, int number);
void search(List *pList, int number);

#endif /* Node_h */

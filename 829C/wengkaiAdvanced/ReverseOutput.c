//
//  ReverseOutput.c
//  829C
//
//  Created by Emma on 2019/5/27.
//  Copyright © 2019 Emma. All rights reserved.
//

#include "ReverseOutput.h"
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *before;
} Node;

void reverseOutput()
{
    Node *head = NULL;
    int number;
    do {
        scanf("%d", &number);
        if (number != -1) {
            Node *p = (Node*)malloc(sizeof(Node));
            p->value = number;
            p->before = head;
            head = p;
        }
    } while (number != -1);
    Node *p;
    for (p = head; p; p = p->before) {
        printf("%d ", p->value);
    }
    printf("\n");
}

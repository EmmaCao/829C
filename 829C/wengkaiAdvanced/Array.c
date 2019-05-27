//
//  Array.c
//  829C
//
//  Created by Emma on 2019/5/27.
//  Copyright © 2019 Emma. All rights reserved.
//

#include "Array.h"

const int BLOCK_SIZE = 20;

//typedef struct{
//    int *array;
//    int size;
//} Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

//封装，将a->size保护起来了，将内部实现细节保护起来了，让使用的人不知道我是如何实现的
int array_size(const Array *a)
{
    return a->size;
}

//以下两个函数可以使用int* array_at(Array *a, int index)一个函数来实现
//int array_get(const Array *a, int index)
//{
//    return a->array[index];
//}
//
//void array_set(Array *a, int index, int value)
//{
//    a->array[index] = value;
//}

//返回int*的原因是可以将该函数当左值来进行赋值
//*array_at(&a, 0) = 10
//printf("%d\n", *array_at(&a, 0));
int* array_at(Array *a, int index)
{
    if (index >= a->size) {
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}

//增长
void array_inflate(Array *a, int more_size)
{
    int *p = (int *)malloc(sizeof(int)*(a->size+more_size));
    //使用memcpy来实现
//    int i;
//    for (i = 0; i< a->size; i++) {
//        p[i] = a->array[i];
//    }
    memcpy((void*)p, (void*)a->array, a->size*sizeof(int));
    
    free(a->array);
    a->array = p;
    a->size += more_size;
}

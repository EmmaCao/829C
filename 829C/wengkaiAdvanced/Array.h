//
//  Array.h
//  829C
//
//  Created by Emma on 2019/5/27.
//  Copyright © 2019 Emma. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int *array;
    int size;
} Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

#endif /* Array_h */

//
//  searchString.c
//  829C
//
//  Created by Emma on 2019/5/24.
//  Copyright © 2019 Emma. All rights reserved.
//

/**
 字符串比对
 题目内容：
 
 题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，而且第一个字符串的长度小于第二个字符串的。你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出-1。
 
 注意，第一个字符的位置是0。
 
 注意，第一个字符串在第二个字符串中的位置可能不止一处。
 
 注意，字符串中可能含有空格。
 
 注意，两个字符串的长度一定大于0。
 
 输入格式:
 
 两个字符串，一行一个。
 
 输出格式：
 
 第一个字符串在第二个字符串中出现的位置，按照从小到到的顺序排列，每个数字后面有一个空格。
 
 如果在第二个字符串中找不到第一个字符串，则输出-1。
 
 输入样例：
 
 abba
 
 ababbba abbabbabbabbaacc
 
 输出样例：
 
 8 11 14 17
 */

#include "searchString.h"
#include <string.h>

void searchString()
{
    char dst[1000];
    char src[1000];
    
    fgets(src, (sizeof(src)/sizeof(src[0])), stdin);
    if (src[strlen(src)-1] == '\n') {
        src[strlen(src)-1] = '\0';
    }
    
    fgets(dst, (sizeof(dst)/sizeof(dst[0])), stdin);
    if (dst[strlen(dst)-1] == '\n') {
        dst[strlen(dst)-1] = '\0';
    }
    
    unsigned long lendst=strlen(dst);
    int flag=1;
    
    if(strstr(dst,src)=='\0'){
        flag=0;
        printf("%d",-1);    //如果dst，src没有相同的字符串，返回-1
    }
    
    const char *p=dst;//创建指针指向dst的第一位
    while(flag){
        p=strstr(p,src);
        if(p=='\0') break;
        unsigned long len=strlen(p);
        printf("%lu ",lendst-len);
        p++;
    }
    
    printf("\n");
}

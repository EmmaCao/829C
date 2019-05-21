//
//  saddlePoint.c
//  829C
//
//  Created by Emma on 2019/5/21.
//  Copyright © 2019 Emma. All rights reserved.
//

/**
 题目内容：
 
 给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
 
 你的任务是找出A的鞍点。
 
 输入格式:
 
 输入的第1行是一个正整数n, （1<=n<=100），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
 
 输出格式：
 
 对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
 
 如果找不到，就输出
 
 NO
 
 题目所给的数据保证了不会出现多个鞍点。
 
 输入样例：
 
 4
 
 1 7 4 1
 
 4 8 3 6
 
 1 6 1 2
 
 0 7 8 9
 
 输出样例：
 
 2 1
 */

#include "saddlePoint.h"

//鞍点
void saddlePoint()
{
    //第一行输入的数字，决定矩阵有几行几列
    int n;
    scanf("%d", &n);
    //输入矩阵
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    //输出矩阵
    printf("矩阵为\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }

    //d判断是否有鞍点的变量，m为在该行的最大值，b,c记录序号
    int d = 0, m, b = 0, c = 0, flag = 0;
    for(int i = 0; i < n; i++){
        m = a[i][0];
        b = i;
        c = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] > m)
            {
                m = a[i][j];
                b = i;
                c = j;
            }
        }
        //找到每行最大值后，假设鞍点存在，后面进行判断，若不存在，则将该标志置为0
        d = 1;
        for(int j = 0; j < n; j++)
        {
            if(m > a[j][c])
            {
                //如果有元素比m小，那么当前点肯定不是鞍点，跳出循环，开始下一行判断
                d = 0;
                break;
            }
        }
        if (d == 1) {
            //不用跳出，因为鞍点可能还有，不止一个
            printf("鞍点为a[%d][%d]=%d\n", b, c, a[b][c]);
            //只要找到鞍点，就将flag置为1
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("NO\n");
    }
}

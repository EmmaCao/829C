//
//  polynomialAddition.c
//  829C
//
//  Created by Emma on 2019/5/21.
//  Copyright © 2019 Emma. All rights reserved.
//

/**
 题目内容：
 
 一个多项式可以表达为x的各次幂与系数乘积的和，比如：
 
 2x6+3x5+12x3+6x+20
 
 现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
 
 程序要处理的幂最大为100。
 
 
 
 输入格式:
 
 总共要输入两个多项式，每个多项式的输入格式如下：
 
 每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
 
 注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。
 
 
 
 输出格式：
 
 从最高幂开始依次降到0幂，如：
 
 2x6+3x5+12x3-6x+20
 
 注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。
 
 
 
 输入样例：
 
 6 2
 
 5 3
 
 3 12
 
 1 6
 
 0 20
 
 6 2
 
 5 3
 
 2 12
 
 1 6
 
 0 20
 
 
 
 输出样例：
 
 4x6+6x5+12x3+12x2+12x+40
 */

#include "polynomialAddition.h"

//多项式加法
void polynomialAddition()
{
    //幂次数组，程序要处理的幂最大为100
    int a[101];
    printf("sizeof(a):%lu sizeof(a[0]):%lu\n", sizeof(a), sizeof(a[0]));
    int len = sizeof(a)/sizeof(a[0]);
    //幂
    int power;
    //系数
    int ratio;
    
    for(int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
    int flag = 0;
    do {
        scanf("%d %d", &power, &ratio);
        if (power == 0) {
            flag++;
        }
        a[power] += ratio;
    } while (flag != 2);
    
    flag = 0;
    for(int i = len-1; i >= 0; i--)
    {
        if (a[i] != 0) {
            if (flag == 1) {
                printf("+");
            }
            flag = 1;
            if (i == 1) {
                printf("%dx", a[i]);
            }
            else if(i == 0)
            {
                printf("%d", a[i]);
            }
            else
            {
                printf("%dx%d", a[i], i);
            }
        }
    }
    printf("\n");
}

//
//  main.c
//  评委打分
//
//  Created by 王皎 on 18/6/27.
//  Copyright © 2018年 王皎. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "stdlib.h"
struct student
{
    char numbers[11];
    char name[30];
    char sex[3];
    char dateofbirth [8];
    char class [10];
    char phoneNo [10];
};
int main()
    {
        float *score, max1=0, max2=0, min1=100, min2=100, sum = 0;
        int i, n;
        printf("judje1,judje2,judge3,judge4,judge5 ");
        scanf("%d", &n);
        score = (float *)malloc(sizeof(float));
        printf("依次输入%d个评委打出的分数：\n", 5);
        for(i = 0; i < n; i++) {
            scanf("%f", score+i);
            sum += score[i];
            if(score[i] > max1) {
                max2 = max1;
                max1 = score[i];
            } else if(score[i] > max2)
                max2 = score[i];
            if(score[i] < min1) {
                min2 = min1;
                min1 = score[i];
            } else if(score[i] < min2)
                min2 = score[i];
        }
        sum -= max1 + min1;
        if(n >= 5) {
            sum -= max2 + min2;
            n -= 4;
        } else n -= 2;
        printf("选手的平均分是: %.2f\n", sum/n);
        return 0;
    }
    

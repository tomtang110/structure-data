//
//  main.c
//  bubbleSort
//
//  Created by 唐楠烊 on 2018/8/19.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>

int main() {
    // insert code here...
    int n=4;
    int i,j;
    int a[4]={2,34,1,5};
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-i;j++){
            if (a[j]>a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}

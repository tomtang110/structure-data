//
//  main.c
//  ShellSort
//
//  Created by 唐楠烊 on 2018/9/1.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#define ARRAYLEN 7
void ShellSort(int a[],int n);
int main() {
    int a[ARRAYLEN] = {4,3,1,8,12,34,5};
    int i;
    ShellSort(a, ARRAYLEN);
    for (i=0;i<ARRAYLEN;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}
void ShellSort(int a[],int n){
    int d,i,j,x;
    d=n/2;
    while(d>=1){
        for (i=d;i<n;i++){
            x = a[i];
            j = i-d;
            while (j>=0 && a[j]>x){
                a[j+d] = a[j];
                j = j-d;
            }
            a[j+d] = x;
        }
        d/=2;
    }
}

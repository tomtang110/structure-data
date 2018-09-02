//
//  main.c
//  InsertSort
//
//  Created by 唐楠烊 on 2018/9/1.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//
#define ARRAYLEN 7
#include <stdio.h>
void InsertSort(int a[],int n);
int main() {
    // insert code here...
    int a[ARRAYLEN]={4,2,3,1,5,12,67};
    InsertSort(a, ARRAYLEN);
    int i;
    for (i=0;i<ARRAYLEN;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}
void InsertSort(int a[],int n){
    int i,j,t;
    for (i=1;i<n;i++){
        t=a[i];
        for (j=i-1;j>=0 && t<a[j];--j){
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
}

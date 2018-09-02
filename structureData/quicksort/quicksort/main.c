//
//  main.c
//  quicksort
//
//  Created by 唐楠烊 on 2018/8/18.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#define ARRAYLEN 11
int Division(int a[],int left,int right);
void Quicksort(int a[],int left, int right);
int main() {
    // insert code here...
    int i, a[ARRAYLEN]={5,4,1,2,6,11,3,12,34,-5};
    Quicksort(a, 0, 9);
    for (i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}
int Division(int a[],int left,int right){
    int base=a[left];
    while (left <right){
        while (left < right && a[right]>base){
            --right;
        }
        a[left] = a[right];
        while (left < right && a[left]<base){
            ++left;
        }
        a[right]=a[left];
    }
    a[left] = base;
    return left;
}
void Quicksort(int a[],int left, int right){
    int i;
    if (left<right){
        i = Division(a, left, right);
        Quicksort(a, left, i-1);
        Quicksort(a, i+1, right);
    }
}

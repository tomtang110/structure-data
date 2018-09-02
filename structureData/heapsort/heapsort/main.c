//
//  main.c
//  heapsort
//
//  Created by 唐楠烊 on 2018/9/1.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#define ARRAYLEN 7
void HeapAdjust(int a[],int s,int n);
void HeapSort(int a[],int n);
int main() {
    // insert code here...
    int i, a[ARRAYLEN]={2,4,1,3,8,14,15};
    HeapSort(a, ARRAYLEN);
    for (i=0;i<ARRAYLEN;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}

void HeapAdjust(int a[],int s,int n){
    int j,t;
    //first node is 0, left childnode = 2*n+1, right child node = 2*n+2
    while (2*s+1<n){ //Having right tree
        j = 2*s + 1;
        if (j+1<n){
            printf("%d-%d\n",a[j],a[j+1]);
            if (a[j]<a[j+1]){ // left < right
                j++;
            }
        }
        if (a[s]<a[j]){
            t = a[s];
            a[s] = a[j];
            a[j] =t;
            s = j;
        }else{
            break;
        }
    }
}
void HeapSort(int a[],int n){
    int t,i;
    for (i=n/2-1;i>=0;i--){
        HeapAdjust(a, i, n);
    }
    for (i=n-1;i>0;i--){
        t = a[0];
        a[0]=a[i];
        a[i] = t;
        HeapAdjust(a, 0, i);
    }
}


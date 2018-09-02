//
//  main.c
//  Simplesearch
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#define ARRAYLEN 5
int SqeSearch(int s[],int n,int key){
    int i;
    for (i=0;s[i]!=key;i++);
    if (i<n){
        return 1;
    }else{
        return -1;
    }
}
int BinarySearch(int s[],int n,int key){
    int low,high,mid;
    low = 0;
    high = n-1;
    
    while (low < high){
        mid = (low+high)/2;
        if (s[mid] == key){
            return mid;
        }else if (s[mid] > key){
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    return -1;
}
int main() {
    // insert code here...
    int a[ARRAYLEN]={1,2,3,4,5};
    printf("please enter a number: ");
    int num,k;
    scanf("%d",&num);
//    a[ARRAYLEN]=num;
    k=BinarySearch(a, ARRAYLEN, num);
    printf("%d\n",k);
    return 0;
}

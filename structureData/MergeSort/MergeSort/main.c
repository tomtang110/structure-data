//
//  main.c
//  MergeSort
//
//  Created by 唐楠烊 on 2018/9/1.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 7
//相邻有序段排序
void MergeStep(int a[],int r[],int s,int m,int n){
    // a是需要排序的数据，s是序列起始序号，m第一个序列结束序号，n是有序序列长度，r表示合并后的数据
    int i,j,k;
    k = s;
    i = s;
    j = m+1;//j是另外一个数组的序号。
    while (i<=m && j<=n){
        if (a[i]<=a[j]){
            //当第一个序列的数小于第二个序列的数
            r[k++] = a[i++];
        }else{
            //当第二个序列的数小于第一个序列的数
            r[k++] = a[j++];
        }
    }
    while (i<=m){//融入残余值
        r[k++] = a[i++];
    }
    while (j<=n){
        r[k++]=a[j++];
    }
}
//完成一遍合并后的函数
void MergePass(int a[],int r[],int n,int len){
    //a代表需要被排序的数据， r保存合并后的数据，n数据长度，len有序表的长度
    int s,e;
    s = 0;
    while (s+len<n){
        e = s+2*len-1;
        if (e>=n){
            e = n-1;
        }
        MergeStep(a, r, s, s+len-1, e);
        s = e +1;
    }
    if (s<n){
        for (;s<n;s++){
            r[s] = a[s];
        }
    }
}
//排序
void MergeSort(int a[],int n){
    int *p;
    int len =1; //有序列表长度
    int f=0; //f是标志
    if (!(p=(int *)malloc(sizeof(int) * n))){
        printf("undergo\n");
        exit(0);
    }
    while (len < n){
        if (f){ //交替在AB间来回合并
            MergePass(p, a, n, len); // 对p合并到a
        }else{
            MergePass(a, p, n, len);//对a合并到p
        }
        len *= 2; // 增加有序序列长度
        f = 1-f; // 使f在0 1变换
    }
    if (f){
        for (f=0;f<n;f++){
            a[f] = p[f];
        }
        free(p);
    }
}
int main() {
    // insert code here...
    int a[ARRAYLEN] = {4,2,12,45,32,46,3};
    int i;
    MergeSort(a, ARRAYLEN);
    for (i=0;i<ARRAYLEN;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}

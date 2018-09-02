//
//  main.c
//  Hashtable
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#define HASH_len 13
#define TABLE_len 8
int data[TABLE_len]={69,65,90,37,92,6,28,54};
int hash[HASH_len]={0};
void InsertHash(int hash[],int m,int data){
    int i=0;
    i = data % 13;
    while (hash[i]){
        i = (i+1) % m;
    }
    hash[i] = data;
}
void CreateHash(int hash[],int m,int data[],int n){
    int i;
    for (i=0;i<n;i++){
        InsertHash(hash, m, data[i]);
    }
}
int HashSearch(int hash[],int m,int key){
    int i;
    i = key % 13;
    while (hash[i] && hash[i] != key){
        i = (i+1)%m;
    }
    if (hash[i]==0){
        return -1;
    }else{
        return i;
    }
}
int main() {
    // insert code here...
    int key,i,pos;
    CreateHash(hash, HASH_len, data, TABLE_len);
    printf("hash elements:");
    for (i=0;i<HASH_len;i++){
        printf("% 1d",hash[i]);
    }
    printf("\n");
    printf("Please enter key: ");
    scanf("%d",&key);
    pos = HashSearch(hash, HASH_len, key);
    if (pos<0){
        printf("fail\n");
    }else{
        printf("the position is %d\n",pos);
    }
    return 0;
}

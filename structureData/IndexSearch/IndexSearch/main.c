//
//  main.c
//  IndexSearch
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include "IndexSearch.h"
#define Table_len 30
#define INDEXTABLE_LEN 3
long stu[Table_len]={
   1080101,1080102,1080103,1080104,1080105,1080106,0,0,0,0,
    1080201,1080202,1080203,1080204,0,0,0,0,0,0,
    1080301,1080302,1080303,1080304,0,0,0,0,0,0
};
INDEXITEM indextable[INDEXTABLE_LEN]={
    {10801,0,6},{10802,10,4},{10803,20,4}
};
int IndexSearch(long key){
    int i,start=0,length=0;
    long index1 = key/100;
    for (i=0;i<INDEXTABLE_LEN;i++){
        if (index1 == indextable[i].index){
            start = indextable[i].start;
            length = indextable[i].length;
            break;
        }
    }
    if (i>=INDEXTABLE_LEN){
        return -1;
    }
    for (i=start;i<start+length;i++){
        if (stu[i]==key){
            return i;
        }
    }
    return -1;
}
int InsertNode(long key){
    int i,start=0,length=0;
    long index1=key/100;
    for (i=0;i<INDEXTABLE_LEN;i++){
        if (index1 == indextable[i].index){
            start = indextable[i].start;
            length = indextable[i].length;
            break;
        }
    }
    if (i>=INDEXTABLE_LEN){
        return -1;
    }else{
        stu[start+length] = key;
        indextable[i].length++;
        return 0;
    }
}
int main() {
    // insert code here...
    long key;
    int i,pos;
    printf("original data: ");
    for (i=0;i<Table_len;i++){
        printf("%ld ",stu[i]);
    }
    printf("\n");
    printf("Please enter key: ");
    scanf("%ld",&key);
    pos = IndexSearch(key);
    if (pos>0){
        printf("Successful, %d position\n",pos);
    }else{
        printf("fail\n");
    }
    printf("insert key: ");
    scanf("%ld",&key);
    if (InsertNode(key)==-1){
        printf("fail\n");
    }else{
        for (i=0;i<Table_len;i++){
            printf("%ld ",stu[i]);
        }
    }
    
    return 0;
}

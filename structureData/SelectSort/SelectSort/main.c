//
//  main.c
//  SelectSort
//
//  Created by 唐楠烊 on 2018/8/18.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>

int main() {
    // insert code here...
    int a[5]={2,3,5,1,9};
    int i,j,t,k;
    for (i=0;i<4;i++){
        k = i;
        for (j=i+1;j<4;j++){
            if (a[k]>a[j]){k=j;}
        }
        t=a[i];
        a[i]=a[k];
        a[k] = t;
    }
    for (i=0;i<5;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}

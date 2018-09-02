//
//  main.c
//  BinaryTreeSeach
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include "BinarysortTree.h"
int main() {
    // insert code here...
    BSTree *t,bst;
    int key;
    int a[]={3,2,5,676,12,345,1,34};
    CreateBST(&bst, a, 8);
    printf("traverse tree: ");
    BST_LDR(&bst);
    BST_Delete(&bst, 345);
    printf("\n after deleting tree: ");
    BST_LDR(&bst);
    printf("\nPlease enter key: ");
    scanf("%d",&key);
    t = SearchBST(&bst, key);
    if(t){
        printf("successful, the address is %p\n",t);
    }else{
        printf("fail\n");
    }
    return 0;
}

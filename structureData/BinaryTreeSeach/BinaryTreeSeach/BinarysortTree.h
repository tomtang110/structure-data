//
//  BinarysortTree.h
//  BinaryTreeSeach
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef BinarysortTree_h
#define BinarysortTree_h

#include <stdio.h>
typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}BSTree;
void InsertBST(BSTree *t,int key);
BSTree *SearchBST(BSTree *t,int key);
void CreateBST(BSTree *t,int data[],int n);
void BST_LDR(BSTree *t);
void BST_Delete(BSTree *t,int key);
#endif /* BinarysortTree_h */

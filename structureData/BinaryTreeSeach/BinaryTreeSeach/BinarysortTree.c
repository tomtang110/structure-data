//
//  BinarysortTree.c
//  BinaryTreeSeach
//
//  Created by 唐楠烊 on 2018/9/2.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "BinarysortTree.h"
#include <stdio.h>
#include <stdlib.h>

void InsertBST(BSTree *t,int key){
    BSTree *p, *parent, *head;
    p = (BSTree *)malloc(sizeof(BSTree));
    p->data=key;
    p->left=p->right = NULL;
    head = t;
    parent = head;
    while(head){
        parent = head;
        if (key<head->data){
            head = head->left;
        }else{
            head = head->right;
        }
    }
    if (key < parent->data){
        parent->left = p;
    }else{
        parent->right = p;
    }
}
BSTree *SearchBST(BSTree *t,int key){
    if (!t || t->data==key){
        return t;
    }else if (key>t->data){
        return SearchBST(t->right, key);
    }else{
        return SearchBST(t->left, key);
    }
}
void CreateBST(BSTree *t,int data[],int n){
    int i;
    t->data=data[0];
    t->left=t->right=NULL;
    for (i=1;i<n;i++){
        InsertBST(t, data[i]);
    }
}
void BST_LDR(BSTree *t){
    BSTree *temp;
    temp =t;
    if (temp){
        BST_LDR(temp->left);
        printf("%d-",temp->data);
        BST_LDR(temp->right);
    }
    return;
}
// Three kind of condition, first is no left and right child tree
// second is only one child tree
// third is having left and right subtree
void BST_Delete(BSTree *t,int key){
    BSTree *p,*parent,*l,*l1;
    int child =0; // 0 is left child tree, 1 right child tree
    if (!t) return;
    p = t;
    parent = p;
    while (p){
        if (p->data == key){
            if (! p->left && !p->right){
                if (p==t){
                    free(p);
                }else if (child ==0){
                    parent ->left =NULL;
                    free(p);
                }else{
                    parent ->right = NULL;
                    free(p);
                }
            }else if (!p->left){
                if (child == 0){//the left subtree of parent
                    parent ->left = p->right;
                }else {
                    parent->right = p->right;
                }
                free(p);
            }else if (!p->right){
                if (child == 0){
                    parent ->left = p->left;
                }else{
                    parent->right = p->left;
                }
                free(p);
            }else{
                l1 = p;
                l = p->right;
                while (l->left){
                    l1 = l;
                    l = l->left;
                }
                p->data = l->data;
                l1->left = NULL;
                free(l1);
            }
            p=NULL;
        }else if (key < p->data){
            child =0;
            parent = p;
            p = p->left;
        }else{
            child =1;
            parent = p;
            p = p->right;
        }
    }
}



















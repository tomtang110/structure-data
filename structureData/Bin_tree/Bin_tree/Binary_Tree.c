//
//  Binary_Tree.c
//  Bin_tree
//
//  Created by 唐楠烊 on 2018/8/11.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "Binary_Tree.h"
#include <stdio.h>
#include <stdlib.h>
ChainBinTree *BinTreeInit(ChainBinTree *node){
    if (node!=NULL){
        return node;
    }else{
        return NULL;
    }
}
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n){
    if(bt==NULL){
        printf("parent node does not exist/n");
        return 0;
    }else{
        switch (n) {
            case 1:
                if (bt->left){
                    printf("left node is full\n");
                    return 0;
                }else{
                    bt ->left = node;
                }
                break;
            case 2:
                if (bt->right){
                    printf("left node is full\n");
                    return 0;
                }else{
                    bt ->right = node;
                }
                break;
            default:
                printf(" n is wrong\n");
                return 0;
                break;
        }
    }
    return 1;
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt){
    if (bt){
        return bt-> left;
    }else{
        return NULL;
    }
}
ChainBinTree *BinTreeRight(ChainBinTree *bt){
    if (bt){
        return bt->right;
    }else{
        return NULL;
    }
}
int BinTreeIsEmpty(ChainBinTree *bt){
    if (bt){
        return 0;
    }else{
        return 1;
    }
}
int BinTreeDepth(ChainBinTree *bt){
    int dep1,dep2;
    if (bt==NULL){
        return 0;
    }else{
        dep1 = BinTreeDepth(bt->left);
        dep2 = BinTreeDepth(bt->right);
        if (dep1>dep2){
            return dep1+1;
        }else{
            return dep2+1;
        }
    }
}
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data){
    ChainBinTree *p;
    if (bt == NULL){
        return NULL;
    }else{
        if (bt->data == data){
            return bt;
        }else{
            p=BinTreeFind(bt->left, data);
            if (p){
                return p;
            }
            p = BinTreeFind(bt->right, data);
            if (p){
                return p;
            }else{
                return NULL;
            }
        }
    }
}
void BinTreeClear(ChainBinTree *bt){
    if (bt){
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt = NULL;
    }
}

void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
    if (bt){
        oper(bt);
        BinTree_DLR(bt->left, oper);
        BinTree_DLR(bt->right, oper);
    }
}
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
    if (bt){
        BinTree_LDR(bt->left, oper);
        oper(bt);
        BinTree_LDR(bt->right, oper);
    }
}
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
    if (bt){
        BinTree_LRD(bt->left, oper);
        BinTree_LRD(bt->right, oper);
        oper(bt);
    }
}
void oper(ChainBinTree *p){
    printf("%c",p->data);
}
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
    ChainBinTree *p;
    ChainBinTree * q[QUEUE_MAXSIZE];
    int head=0,tail=0;
    if (bt){
        tail = (tail+1)%QUEUE_MAXSIZE;
        q[tail]=bt;
    }
    while (head != tail){
        head = (head+1)%QUEUE_MAXSIZE;
        p=q[head];
        oper(p);
        if (p->left!=NULL){
            tail = (tail+1)%QUEUE_MAXSIZE;
            q[tail] = p->left;
        }
        if (p->right != NULL){
            tail = (tail+1)%QUEUE_MAXSIZE;
            q[tail] = p->right;
        }
    }
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        


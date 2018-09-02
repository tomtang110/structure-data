//
//  ThreadBinTree.c
//  ThreadBinTree
//
//  Created by 唐楠烊 on 2018/8/12.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "ThreadBinTree.h"

#include <stdlib.h>
#include <stdio.h>
ThreadBinTree *Previous = NULL;
ThreadBinTree *BinTreeInit(ThreadBinTree *node){
    if (node!=NULL){
        return node;
    }else{
        return NULL;
    }
}
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n){
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
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt){
    if (bt){
        return bt-> left;
    }else{
        return NULL;
    }
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt){
    if (bt){
        return bt->right;
    }else{
        return NULL;
    }
}
int BinTreeIsEmpty(ThreadBinTree *bt){
    if (bt){
        return 0;
    }else{
        return 1;
    }
}
int BinTreeDepth(ThreadBinTree *bt){
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
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data){
    ThreadBinTree *p;
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
void BinTreeClear(ThreadBinTree *bt){
    if (bt){
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt = NULL;
    }
}


void BinTree_LDR(ThreadBinTree *bt){
    if (bt){
        BinTree_LDR(bt->left);
        bt ->Lflag=(bt->left)?SubTree:Thread;
        bt ->Rflag=(bt->right)?SubTree:Thread;
        if (Previous){
            if (Previous->Rflag==Thread){
                Previous->right=bt; // back sign
            }
            if (bt->Lflag==Thread){
                bt->left=Previous; // previous sign
            }
        }
        Previous=bt;
        BinTree_LDR(bt->right);
    }
}
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt){
    ThreadBinTree *nextnode;
    if(!bt) return NULL;
    if (bt->Rflag==Thread){
        return bt->right;
    }else{
        nextnode = bt->right;
        while (nextnode->Lflag==SubTree){
            nextnode = bt->left;
        }
        return nextnode;
    }
}
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt){
    ThreadBinTree *prenode;
    if(!bt) return NULL;
    if (bt->Lflag==Thread){
        return bt->left;
    }else{
        prenode = bt->left;
        while (prenode->Rflag==SubTree){
            prenode = bt->left;
        }
        return prenode;
}
}
void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)){
    if (bt){
        while (bt->Lflag==SubTree){
            bt = bt->left;
        }
        do {
            oper(bt);
            bt = BinTreeNext_LDR(bt);
        }while(bt);
    }
    
        }
void oper(ThreadBinTree *p){
    printf("%c",p->data);
}


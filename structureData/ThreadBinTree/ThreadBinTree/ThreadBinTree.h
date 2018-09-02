//
//  ThreadBinTree.h
//  ThreadBinTree
//
//  Created by 唐楠烊 on 2018/8/12.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef ThreadBinTree_h
#define ThreadBinTree_h

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;
typedef enum{
    SubTree,
    Thread
}NodeFlag;

typedef struct threadTree{
    DATA data;
    NodeFlag Lflag;
    NodeFlag Rflag;
    struct threadTree *left;
    struct threadTree *right;
}ThreadBinTree;




ThreadBinTree *BinTreeInit(ThreadBinTree *node);
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n);
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt);
ThreadBinTree *BinTreeRight(ThreadBinTree *bt);
int BinTreeIsEmpty(ThreadBinTree *bt);
int BinTreeDepth(ThreadBinTree *bt);
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data);
void BinTreeClear(ThreadBinTree *bt);
void BinTree_LDR(ThreadBinTree *bt);
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt);
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt);
void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));
void oper(ThreadBinTree *p);

#endif /* ThreadBinTree_h */

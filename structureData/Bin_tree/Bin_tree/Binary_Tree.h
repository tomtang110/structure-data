//
//  Binary_Tree.h
//  Bin_tree
//
//  Created by 唐楠烊 on 2018/8/11.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef Binary_Tree_h
#define Binary_Tree_h

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;
typedef struct ChainTree{
    DATA data;
    struct ChainTree *left;
    struct ChainTree *right;
}ChainBinTree;
ChainBinTree *BinTreeInit(ChainBinTree *node);
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n);
ChainBinTree *BinTreeLeft(ChainBinTree *bt);
ChainBinTree *BinTreeRight(ChainBinTree *bt);
int BinTreeIsEmpty(ChainBinTree *bt);
int BinTreeDepth(ChainBinTree *bt);
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data);
void BinTreeClear(ChainBinTree *bt);
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p));
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p));
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p));
void oper(ChainBinTree *p);
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p));
#endif /* Binary_Tree_h */

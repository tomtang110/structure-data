//
//  traversing.h
//  graph
//
//  Created by 唐楠烊 on 2018/8/17.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef traversing_h
#define traversing_h

#include <stdio.h>
#include "graph.h"
#define QUEUE_MAXSIZE 30
typedef struct {
    int Data[QUEUE_MAXSIZE];
    int head;
    int tail;
}Sequeue;
void QueueInit(Sequeue *q);
int QueueIsEmpty(Sequeue q);
int QueueIn(Sequeue *q,int n);
int QueueOut(Sequeue *q,int *ch);

void DFSTraverse(MatrixGraph *G);
void BFSTraverse(MatrixGraph *G);
void DFSM(MatrixGraph *G,int i);
void BFSM(MatrixGraph *G,int i);
#endif /* traversing_h */

//
//  traversing.c
//  graph
//
//  Created by 唐楠烊 on 2018/8/17.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "traversing.h"
#include <stdio.h>

void DFSTraverse(MatrixGraph *G){
    int i;
    for (i=0;i<G->VertexNum;i++){
        G->isTrav[i]=0;
    }
    printf("DFS traverse all node: ");
    for (i=0;i<G->VertexNum;i++){
        if (! G->isTrav[i]){
            DFSM(G, i);
        }
    }
    printf("\n");
}
void DFSM(MatrixGraph *G,int i){
    int j;
    G->isTrav[i] = 1;
    printf("->%c",G->Vertex[i]);
    for (j=0;j<G->VertexNum;j++){
        if (G->Edges[i][j] != MAXVALUE && !(G->isTrav[j])){
            DFSM(G, j);
        }
    }
}
void BFSTraverse(MatrixGraph *G){
    int i;
    for (i=0;i<G->VertexNum;i++){
        G->isTrav[i]=0;
    }
    printf("BFS traverse all node: ");
    for (i=0;i<G->VertexNum;i++){
        if (! G->isTrav[i]){
            BFSM(G, i);
        }
    }
    printf("\n");
}
void BFSM(MatrixGraph *G,int k){
    int i,j;
    Sequeue Q;
    QueueInit(&Q);
    G->isTrav[k]=1;
    printf("->%c",G->Vertex[k]);
    QueueIn(&Q, k);
    while (!QueueIsEmpty(Q)){
        QueueOut(&Q, &i);
        for (j=0;j<G->VertexNum;j++){
                if (G->Edges[i][j] != MAXVALUE && !(G->isTrav[i])){
                    printf("->%c",G->Vertex[j]);
                     G->isTrav[j]=1;
                    QueueIn(&Q, j);
                }
        }
    }
}

void QueueInit(Sequeue *q){
    q->head = q->tail=0;
}
int QueueIsEmpty(Sequeue q){
    return q.head==q.tail;
}
int QueueIn(Sequeue *q,int ch){
    if ((q->tail+1)%QUEUE_MAXSIZE==q->head){
        return 0;
    }
    q->Data[q->tail]=ch;
    q->tail = (q->tail+1)% QUEUE_MAXSIZE;
    return 1;
}
int QueueOut(Sequeue *q,int *ch){
    if ((q->tail+1)%QUEUE_MAXSIZE==q->head){
        return 0;
    }
    *ch = q->Data[q->head];
    q->head = (q->head+1)%QUEUE_MAXSIZE;
    return 1;
}



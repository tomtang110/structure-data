//
//  Listgraph.h
//  ListGraph
//
//  Created by 唐楠烊 on 2018/8/15.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef Listgraph_h
#define Listgraph_h

#include <stdio.h>
#define VERTEX_MAX 20
typedef struct edgenode{
    int Vertex;
    int weight;
    struct edgenode *next;
}EdgeNode;
typedef struct {
    EdgeNode *AdjList[VERTEX_MAX];
    int VertexNum,EdgeNum;
    int Graphtype;
}ListGraph;
void CreateGraph(ListGraph *G);
void OutList(ListGraph *G);
#endif /* Listgraph_h */

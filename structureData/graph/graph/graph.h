//
//  graph.h
//  graph
//
//  Created by 唐楠烊 on 2018/8/14.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#define VERTEX_MAX 26
#define MAXVALUE 32676
typedef struct {
    char Vertex[VERTEX_MAX];
    int Edges[VERTEX_MAX][VERTEX_MAX];
    int isTrav[VERTEX_MAX];
    int VertexNum;
    int EdgeNum;
    int GraphType; // 0 is undirect graph, 1. direct graph
}MatrixGraph;
void CreateMatrixGraph(MatrixGraph *G);
void OutMatrix(MatrixGraph *G);

#endif /* graph_h */

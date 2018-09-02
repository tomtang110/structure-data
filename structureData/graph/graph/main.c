//
//  main.c
//  graph
//
//  Created by 唐楠烊 on 2018/8/14.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include "graph.h"
#include "traversing.h"
int main() {
    // insert code here...
    MatrixGraph G;
    int i,j;
    printf("please enter the type of graph: ");
    scanf("%d",&G.GraphType);
    printf("Please enter the number of vertex and edges: ");
    scanf("%d%d",&G.VertexNum,&G.EdgeNum);
    for (i=0;i<G.VertexNum;i++){
        for (j=0;j<G.VertexNum;j++){
            G.Edges[i][j]=MAXVALUE;
        }
    }
    CreateMatrixGraph(&G);
    printf("the neighbor matrix: \n");
    OutMatrix(&G);
    DFSTraverse(&G);
    BFSTraverse(&G);
    
    return 0;
}

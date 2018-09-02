//
//  graph.c
//  graph
//
//  Created by 唐楠烊 on 2018/8/14.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateMatrixGraph(MatrixGraph *G){
    int j,i,k,weight;
    char start,end;
    printf("Please enter vertice information:");
    for (i=0;i<G->VertexNum;i++){
        printf("the %d vertex: ",i+1);
        getchar();
        scanf("%c",&(G->Vertex[i]));
       
    }
    printf("Please enter both vertex of edges,and weight:\n");
    for (k=0;k<G->EdgeNum;k++){
        printf("The %d edge: ",k+1);
        getchar();
        scanf("%c %c %d",&start,&end,&weight);
        
        for (i=0;start!=G->Vertex[i];i++);
        for (j=0;end!=G->Vertex[j];j++);
        G->Edges[i][j]=weight;
        if (G->GraphType==0){
            G->Edges[j][i]=weight;
        }
            
    }
}
void OutMatrix(MatrixGraph *G){
    int i,j;
    for (j=0;j<G->VertexNum;j++){
        printf("\t%c",G->Vertex[j]);
    }
    printf("\n");
    for (i=0;i<G->VertexNum;i++){
        printf("%c",G->Vertex[i]);
        for (j=0;j<G->VertexNum;j++){
            if (G->Edges[i][j]==MAXVALUE){
                printf("\tINF");
            }else{
                printf("\t%d",G->Edges[i][j]);
            }
        }
        printf("\n");
    }
}

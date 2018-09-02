//
//  Listgraph.c
//  ListGraph
//
//  Created by 唐楠烊 on 2018/8/15.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include "Listgraph.h"
#include <stdio.h>
#include <stdlib.h>
void CreateGraph(ListGraph *G){
    int i,weight;
    int start,end;
    EdgeNode *s;
    for (i=1;i<=G->VertexNum;i++){
        G->AdjList[i]=NULL;
    }
    for (i=1;i<=G->EdgeNum;i++){
        getchar();
        printf("the %d edge: ",i);
        scanf(" %d %d %d",&start,&end,&weight);
        s = (EdgeNode *)malloc(sizeof(EdgeNode));
        s->next = G->AdjList[start];
        s->Vertex=end;
        s->weight=weight;
        G->AdjList[start]=s;
        if (G->Graphtype==0){
            s =(EdgeNode *)malloc(sizeof(EdgeNode));
            s->next = G->AdjList[end];
            s->Vertex = start;
            s->weight = weight;
            G->AdjList[end] = s;
        }
    }
}
void OutList(ListGraph *G){
    int i;
    EdgeNode *s;
    for (i=1;i<=G->VertexNum;i++){
        printf("vertex %d:",i);
        s = G->AdjList[i];
        while(s){
            printf("->%d(%d)",s->Vertex,s->weight);
            s=s->next;
        }
        printf("\n");
    }
}

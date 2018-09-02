//
//  main.c
//  ListGraph
//
//  Created by 唐楠烊 on 2018/8/15.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include "Listgraph.h"
int main() {
    // insert code here...
    ListGraph G;
    printf("enter the type of graph(0:undirect graph,1:direct graph): ");
    scanf("%d",&G.Graphtype);
    printf("enter the number of vertex and edges: ");
    scanf("%d %d",&G.VertexNum,&G.EdgeNum);
    printf("enter the two neighbor vertex and weight constructing edges: ");
    CreateGraph(&G);
    printf("enter the adjTable:\n");
    OutList(&G);
    getchar();

    return 0;
}

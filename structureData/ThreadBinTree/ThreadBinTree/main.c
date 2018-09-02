//
//  main.c
//  Bin_tree
//
//  Created by 唐楠烊 on 2018/8/11.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ThreadBinTree.h"

ThreadBinTree *InitRoot(){
    ThreadBinTree *node;
    node = (ThreadBinTree *)malloc(sizeof(ThreadBinTree));
    if (node){
        printf("\n enter the root node data:");
        scanf("%c",&node->data);
        scanf("%*c");
        node->left=NULL;
        node->right=NULL;
        return BinTreeInit(node);
    }
    return NULL;
}
void AddNode(ThreadBinTree *bt){
    ThreadBinTree *node,*parent;
    DATA data;
    char select;
    node =(ThreadBinTree *)malloc(sizeof(ThreadBinTree));
    if (node){
        printf("\n enter the bin-Tree node data:");
        scanf("%c",&node->data);
        scanf("%*c");
        node->left = NULL;
        node -> right = NULL;

        printf("\n enter the parent node data:");
        scanf("%c",&data);
        scanf("%*c");
        parent=BinTreeFind(bt, data);
        if (!parent){
            printf("cannot find parent node\n");
            free(node);
            return;
        }
        printf("1.add left_node\n2.add right_node\n");
        do{
            scanf("%c",&select);
            scanf("%*c");
            select -= '0';
            if (select == 1||select ==2){
                BinTreeAddNode(parent, node, select);
            }

        }while(select != 1 && select != 2);
    }
}
int main() {
//     insert code here...
    ThreadBinTree *root = NULL;
    char select;
    void (*oper1)(ThreadBinTree *p);
    oper1= oper;
    do{
        printf("\n1.set root element      2.add tree node\n");
        printf("4.Establish threadBinTree for LDR          5.find back\n");

        scanf("%c",&select);
        scanf("%*c");
        switch(select){
            case '1':
                root = InitRoot();
                break;
            case '2':
                AddNode(root);
                break;

            case '4':
                BinTree_LDR(root);
                break;
            case '5':
                ThreadBinTree_LDR(root,oper1);
                
            case '0':
                break;
        }
    }while(select != '0');

    
    printf("a\n");
    return 0;
    
}


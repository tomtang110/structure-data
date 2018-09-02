//
//  main.c
//  Bin_tree
//
//  Created by 唐楠烊 on 2018/8/11.
//  Copyright © 2018年 唐楠烊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Binary_Tree.h"
ChainBinTree *InitRoot(){
    ChainBinTree *node;
    node = (ChainBinTree *)malloc(sizeof(ChainBinTree));
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
void AddNode(ChainBinTree *bt){
    ChainBinTree *node,*parent;
    DATA data;
    char select;
    node =(ChainBinTree *)malloc(sizeof(ChainBinTree));
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
    // insert code here...
    ChainBinTree *root = NULL;
    char select;
    void (*oper1)(ChainBinTree *p);
    oper1= oper;
    do{
        printf("\n1.set root element      2.add tree node\n");
        printf("3.DLR                      4.LDR\n");
        printf("5.LRD                     6.LEVEL\n");
        printf("7.Deep                    8.exit\n");
        
        scanf("%c",&select);
        scanf("%*c");
        switch(select){
            case '1':
                root = InitRoot();
                break;
            case '2':
                AddNode(root);
                break;
            case '3':
                printf("\n the result of DLR: ");
                BinTree_DLR(root, oper1);
                printf("\n");
                break;
            case '4':
                printf("\n the result of LDR: ");
                BinTree_LDR(root, oper1);
                printf("\n");
                break;
            case '5':
                printf("\n the result of LRD: ");
                BinTree_LRD(root, oper1);
                printf("\n");
                break;
            case '6':
                printf("\n the result of level: ");
                BinTree_Level(root, oper1);
                printf("\n");
            case '7':
                printf("The depth is %d\n",BinTreeDepth(root));
                break;
            case '0':
                break;
        }
    }while(select != '0');
    
    BinTreeClear(root);
    root = NULL;
    return 0;
        
}

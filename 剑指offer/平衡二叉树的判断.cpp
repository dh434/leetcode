#include<iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
#include <stdio.h>  
#include <time.h>  
#include <windows.h>  
#include <exception> 
using namespace std;
#include <utility>

//二叉树结点结构
typedef struct BiTNode{
    char ch;            //结点数据
    struct BiTNode *lchild;        //左孩子
    struct BiTNode *rchild;        //右孩子
}BiTNode,*BiTree;

bool isBalanced(BiTNode* pRoot, int* pDepth){
    if(pRoot == NULL){
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(isBalanced(pRoot->lchild, &left) && isBalanced(pRoot->rchild, &right)){
        int diff = left - right;
        if(diff < 1 && diff > -1){
            *pDepth = 1 + (left>right? left:right);
            return true;
        }
    }
    return false;
}

bool isBalanced(BiTNode* pRoot){
    int depth = 0;
    return isBalanced(pRoot, &depth);
}
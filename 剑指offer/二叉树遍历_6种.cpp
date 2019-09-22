#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
using namespace std;


//二叉树结点结构
typedef struct BiTNode{
    char ch;            //结点数据
    struct BiTNode *lchild;        //左孩子
    struct BiTNode *rchild;        //右孩子
}BiTNode,*BiTree;

// 前序

void PreOrder(BiTNode *pRoot){
    if(pRoot){
        cout << pRoot->ch << " ";
        PreOrder(pRoot->lchild);
        PreOrder(pRoot->rchild);
    }
}

void PreOrder_Nor(BiTNode *pRoot){
    if(pRoot == NULL){
        return ;
    }

    std::stack<BiTNode*> nodes;
    nodes.push(pRoot);

    BiTNode* ptemp = NULL;
    while(!nodes.empty()){
        ptemp = nodes.top();
        cout << ptemp->ch << " ";
        nodes.pop();

        if(ptemp->rchild != NULL){
            nodes.push(ptemp->rchild);
        }
        if(ptemp->lchild != NULL){
            nodes.push(ptemp->lchild);
        }

    }

    cout << endl;

}

//中序
void InOrder(BiTNode *pRoot){
    if(pRoot){
        PreOrder(pRoot->lchild);
        cout << pRoot->ch << " ";
        PreOrder(pRoot->rchild);
    }
}

void InOrder_Nor(BiTNode *pRoot,vector<int> &path){
    stack<BiTNode*> nodes;
    BiTNode* p = pRoot;

    while(p!=NULL || !nodes.empty()){
        while(p!=NULL){
            nodes.push(p);
            p = p->lchild;
        }

        if(!nodes.empty()){
            p = nodes.top();
            path.push_back(p->ch);

            nodes.pop();
            p = p->rchild;

        }
    }

}



// 后序

void PostOrder(BiTNode *pRoot){
    if(pRoot){
        PreOrder(pRoot->lchild);
        PreOrder(pRoot->rchild);
        cout << pRoot->ch << " ";
    }
}

void PostOrder_Nor(BiTNode *pRoot, vector<int>&path){

    stack<pair<BiTNode*,bool>> nodes;
    nodes.push(make_pair(pRoot,false)) ;
    bool visited;
    BiTNode* pTemp=NULL;
    while(!nodes.empty()){
        pTemp = nodes.top().first;
        visited = nodes.top().second;
        nodes.pop();
        if(pTemp == NULL)
            continue;
        if(visited){
            path.push_back(pTemp->ch);
        }
        else{
            nodes.push(make_pair(pRoot,true));
            nodes.push(make_pair(pTemp->rchild,false));
            nodes.push(make_pair(pTemp->lchild,false));
        }

    }

}


//层序
void LevelOrder(BiTNode *pRoot){
    queue<BiTNode *> q;

    if(pRoot == NULL)
        return ;
    
    q.push(pRoot);
    BiTNode* pTemp=NULL;

    while(!q.empty()){
        pTemp = q.front();
        cout << pTemp->ch << " ";
        if (pTemp->lchild != NULL){
            q.push(pTemp->lchild);
        }
        if(pTemp->rchild != NULL){
            q.push(pTemp->rchild);
        }
        q.pop();
    }

    cout << endl;

}
#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
#include <exception>

using namespace std;

// 根据中序和前序来重构二叉树
// 递规的思想，关键是要注意异常情况的处理，以及指针加减，传递的正确性


//二叉树结点结构
typedef struct BiTNode{
    char ch;            //结点数据
    struct BiTNode *lchild;        //左孩子
    struct BiTNode *rchild;        //右孩子
}BiTNode,*BiTree;


BiTNode* ConstructTree(int *preorder, int *inorder, int length){
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BiTNode* ConstructCore(int *start_preorder, int *end_preorder, int *start_inorder, int *end_inorder){

    int rootValue = start_preorder[0];
    BiTNode* root = new BiTNode();
    root->ch = rootValue;
    root->lchild = root->rchild = NULL;

    if(start_preorder == end_preorder){
        if(start_inorder == end_inorder && start_inorder[0] == start_preorder[0])
            return root;
        else
            throw std::exception("Invalid input.");
    }

    //在中序中找到根节点
    int *rootInorder = start_inorder;
    while(rootInorder < end_inorder && *rootInorder != rootValue)
        ++ rootInorder;
    
    if(rootInorder == end_inorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");
    
    int leftLength = rootInorder - start_inorder;
    int *leftPreorderEnd = start_preorder + leftLength;
    if(leftLength > 0){
        root->lchild = ConstructCore(start_preorder + 1, leftPreorderEnd, start_inorder, rootInorder -1);
    }
    if(leftLength < end_preorder - start_preorder){
        root->rchild = ConstructCore(leftPreorderEnd + 1, end_preorder, rootInorder+1, end_inorder);
    }
    return root;
}
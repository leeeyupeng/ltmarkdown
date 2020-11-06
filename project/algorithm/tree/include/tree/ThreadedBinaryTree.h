#pragma once
#include<vector>
using namespace std;
enum eFlag{
    LINK,
    CLUE,
};
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    eFlag lFlag;
    eFlag rFlag;
    TreeNode(int _val):val(_val),left(NULL),right(NULL),lFlag(eFlag::LINK),rFlag(eFlag::LINK){}
};

//二叉树的中序遍历
void inorder(TreeNode* node,vector<int>&ans){
    if(node==NULL){return;}
    inorder(node->left,ans);
    ans.push_back(node->val);
    inorder(node->right,ans);
}
vector<int> inorderTraversal(TreeNode* node){
    vector<int> ans;
    inorder(node,ans);
    return ans;
}
//二叉树的中序线索化
void _inorderCreateBTB(TreeNode* node,TreeNode* &pre){
    if(node==NULL){return;}    
    if(node->left==NULL){
        node->left=pre;
        node->lFlag = eFlag::CLUE;
    }
    else{
        _inorderCreateBTB(node->left,pre);
    }
    if(pre!=NULL && pre->right==NULL){
        pre->right = node;
        pre->rFlag = eFlag::CLUE;
    }
    pre = node;
    _inorderCreateBTB(node->right,pre);

}
void inorderCreateBTB(TreeNode* node){
    TreeNode* pre = NULL;
    _inorderCreateBTB(node,pre);
}
//遍历中序线索二叉树
vector<int> inorderTraversalBTB(TreeNode* node){
    vector<int> ans;
    if(node==NULL){return ans;}    
    TreeNode* curNode = node;
    while(curNode!=NULL){
        while(curNode->lFlag == eFlag::LINK){curNode = curNode->left;}
        ans.push_back(curNode->val);
        while(curNode->rFlag == eFlag::CLUE){curNode = curNode->right;ans.push_back(curNode->val);}
        curNode=curNode->right;
    }
    return ans;
}
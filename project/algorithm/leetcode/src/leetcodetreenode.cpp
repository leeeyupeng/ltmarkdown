#include"leetcode.h"
#include"leetcodenode.h"

TreeNode *GetTree(vector<int>& tree){
    int n = tree.size();
    if(n == 0){return NULL;}
    TreeNode *root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while(!q.empty() && index<n){
        TreeNode *node = q.front();
        q.pop();
        if(tree[index]!=null){node->left = new TreeNode(tree[index]);q.push(node->left);}
        index++;
        if(index<n){
            if(tree[index]!=null){node->right = new TreeNode(tree[index]);q.push(node->right);}
            index++;
        }
    }
    return root;
}
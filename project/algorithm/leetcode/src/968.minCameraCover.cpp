#include"leetcode.h"


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
#define MIN(x,y,z) min(x,min(y,z))
class Solution {
    struct Node{
        int dp[3];
        Node(int a,int b,int c){dp[0] = a;dp[1] = b;dp[2] = c;}
    };
private:
    Node dfs(TreeNode *node){
        if(node==NULL){return Node(0,0,0);}
        else if(node->left == NULL && node->right == NULL){return Node(1,1,0);}
        Node left = dfs(node->left);
        Node right = dfs(node->right);
        int dp0 = MIN(left.dp[0],left.dp[1],left.dp[2]) + MIN(right.dp[0],right.dp[1],right.dp[2]) + 1;
        int dp1 = left.dp[0]+right.dp[0];
        if(left.dp[0]!=0){
            dp1 = min(dp1,left.dp[0]+right.dp[1]);
        }
        if(right.dp[0]!=0){
            dp1 = min(dp1,left.dp[1] + right.dp[0]);
        }
        int dp2 = min(left.dp[0],left.dp[1]) + min(right.dp[0] , right.dp[1]);
        Node now = Node(dp0,dp1,dp2);
        
        return now;
    }
public:
    int minCameraCover(TreeNode* root) {
        Node ans = dfs(root);
        return min(ans.dp[0],ans.dp[1]);
    }
};
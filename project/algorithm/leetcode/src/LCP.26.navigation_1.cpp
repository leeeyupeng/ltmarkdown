#include"leetcode.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

#define INFINITY 100000
class Solution {
    // 0 不需要装置 不提供装置
    // 1 提供装置
    // 2 需要装置   需要装置的时候能不能提供装置呢？[1,2,null,3,4]
    // 3 需要装置   一条线
    struct State{
        int states[3];
        State(int s0,int s1,int s2){states[0] = s0,states[1] = s1,states[2]=s2;}
    };
private:
    State dfs(TreeNode *node){
        if(node->left==NULL && node->right==NULL){return State(1,1,0);}

        State stateNow(INFINITY,INFINITY,INFINITY);
        if(node->left!=NULL&&node->right!=NULL){
            State stateLeft = dfs(node->left);
            State stateRight = dfs(node->right);
            stateNow.states[0] = min(stateNow.states[0],stateLeft.states[1]+stateRight.states[2]);
            stateNow.states[0] = min(stateNow.states[0],stateLeft.states[2]+stateRight.states[1]);
            //需要装置的时候能不能提供装置呢？
            if(stateLeft.states[2]!=0 && stateRight.states[2] != 0){
                stateNow.states[0] = min(stateNow.states[0],stateLeft.states[0]+stateRight.states[0]);
                stateNow.states[0] = min(stateNow.states[0],stateLeft.states[2]+stateRight.states[2]);
            }

            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[1]+stateRight.states[1]);
            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[0]+stateRight.states[1]);
            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[1]+stateRight.states[0]);
            if(stateLeft.states[2]!=0){
                stateNow.states[1] = min(stateNow.states[1],stateLeft.states[2]+stateRight.states[1]);
            }
            if(stateRight.states[2]!=0){
                stateNow.states[1] = min(stateNow.states[1],stateLeft.states[1]+stateRight.states[2]);
            }
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[0]+stateRight.states[2]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[2]+stateRight.states[0]);
            if(stateLeft.states[2]!=0 || stateRight.states[2] != 0){
                stateNow.states[2] = min(stateNow.states[2],stateLeft.states[0]+stateRight.states[0]);
                stateNow.states[2] = min(stateNow.states[2],stateLeft.states[2]+stateRight.states[2]);
            }
            stateNow.states[0] = min(stateNow.states[0],stateNow.states[1]);
        }
        else if(node->left!=NULL){
            State stateLeft = dfs(node->left);
            stateNow = State(stateLeft.states[0],stateLeft.states[1],stateLeft.states[2]);
            stateNow.states[0]=stateLeft.states[1];
        }
        else if(node->right!=NULL){
            State stateRight = dfs(node->right);
            stateNow = State(stateRight.states[0],stateRight.states[1],stateRight.states[2]);
            stateNow.states[0]=stateRight.states[1];
        }
        return stateNow;
    }
public:
    int navigation(TreeNode* root) {
        State state = dfs(root);
        int ans = INFINITY;
        ans = min(ans,state.states[0]);
        ans = min(ans,state.states[1]);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     // TreeNode* root = new TreeNode(1);
//     // root->left=new TreeNode(2);
//     // root->left->left = new TreeNode(3);
//     // root->left->right = new TreeNode(4);

//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);

//     int ans = solution.navigation(root);

//     return 0;
// }
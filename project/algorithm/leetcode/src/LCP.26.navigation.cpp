#include"leetcode.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

#define INFINITY INT_MAX
class Solution {
    struct State{
        int states[4];
        State(int s0,int s1,int s2,int s3){states[0] = s0,states[1] = s1,states[2]=s2;states[3] = s3;}
    };
private:
    State dfs(TreeNode *node){
        if(node->left==NULL && node->right==NULL){return State(0,INFINITY,1,INFINITY);}

        State now(INFINITY,INFINITY,INFINITY,INFINITY);
        if(node->left!=NULL && node->right !=NULL){
            State left = dfs(node->left);
            State right = dfs(node->right);
            now.states[0] = INFINITY;
            
            if(left.states[2]!= INFINITY && right.states[1]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[2] + right.states[1]);
            }
            if(left.states[2]!= INFINITY && right.states[3]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[2] + right.states[3]);
            }
            if(left.states[1]!= INFINITY && right.states[2]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[1] + right.states[2]);
            }
            if(left.states[3]!= INFINITY && right.states[2]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[3] + right.states[2]);
            }

            if(left.states[2]!= INFINITY && right.states[0]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[2] + right.states[0]);
            }
            if(left.states[0]!= INFINITY && right.states[2]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[0] + right.states[2]);
            }

            if(left.states[1]!= INFINITY && right.states[0]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[1] + right.states[0]);
            }
            if(left.states[0]!= INFINITY && right.states[1]!=INFINITY){
                now.states[1] = min(now.states[1],left.states[0] + right.states[1]);
            }

            // if(left.states[1]!= INFINITY && right.states[0]!=INFINITY){
            //     now.states[1] = min(now.states[1],left.states[1] + right.states[0]);
            // }
            // if(left.states[0]!= INFINITY && right.states[1]!=INFINITY){
            //     now.states[1] = min(now.states[1],left.states[0] + right.states[1]);
            // }

            if(left.states[2]!= INFINITY && right.states[2]!=INFINITY){
                now.states[2] = min(now.states[2],left.states[2] + right.states[2]);
            }
            if(left.states[2]!= INFINITY && right.states[3]!=INFINITY){
                now.states[2] = min(now.states[2],left.states[2] + right.states[3]);
            }
            if(left.states[3]!= INFINITY && right.states[2]!=INFINITY){
                now.states[2] = min(now.states[2],left.states[3] + right.states[2]);
            }

            if(left.states[3]!= INFINITY && right.states[3]!=INFINITY){
                now.states[2] = min(now.states[2],left.states[3] + right.states[3]);
            }

            if(left.states[1]!= INFINITY && right.states[2]!=INFINITY){
                now.states[3] = min(now.states[3],left.states[1] + right.states[2]);
            }
            if(left.states[3]!= INFINITY && right.states[2]!=INFINITY){
                now.states[3] = min(now.states[3],left.states[3] + right.states[2]);
            }

            if(left.states[2]!= INFINITY && right.states[1]!=INFINITY){
                now.states[3] = min(now.states[3],left.states[2] + right.states[1]);
            }
            if(left.states[2]!= INFINITY && right.states[3]!=INFINITY){
                now.states[3] = min(now.states[3],left.states[2] + right.states[3]);
            }
            if(left.states[3]!= INFINITY && right.states[3]!=INFINITY){
                now.states[3] = min(now.states[3],left.states[3] + right.states[3]);
            }
        }
        else if(node->left!=NULL){
            State left = dfs(node->left);
            now = left;
            //now.states[3] = INFINITY;
        }
        else if(node->right!=NULL){
            State right = dfs(node->right);
            now = right;
            //now.states[3] = INFINITY;
        }
        return now;
    }
public:
    int navigation(TreeNode* root) {
        State state = dfs(root);
        int ans = INFINITY;
        // if(state.states[0] != INFINITY){
        //     ans = min(ans,state.states[0] + 1);
        // }
        if(state.states[1]!=INFINITY){
            ans = min(ans,state.states[1] + 1);
        }
        if(state.states[2]!=INFINITY){
            ans = min(ans,state.states[2]);
        }
        if(state.states[3]!=INFINITY){
            ans = min(ans,state.states[3]);
        }
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
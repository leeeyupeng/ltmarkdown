#include"leetcode.h"
#include"leetcodenode.h"
 

#define INFINITY 100000
class Solution {    
    // 0 不提供装置 需要装置   一条线 这种情况 子树没有装置
    // 1 半提供装置 不需要装置 
    // 2 提供装置 不需要装置
    // 3 半提供装置 需要装置
    // 什么叫半提供装置，就是子树有装置 但是不完全提供装置
    // 状态转移 判断四种状态相互组合的转移方程
    struct State{
        int states[4];
        State(int s0,int s1,int s2,int s3){states[0] = s0,states[1] = s1,states[2]=s2;states[3] = s3;}
    };
private:
    State dfs(TreeNode *node){
        if(node->left==NULL && node->right==NULL){return State(0,INFINITY,1,INFINITY);}

        State stateNow(INFINITY,INFINITY,INFINITY,INFINITY);
        if(node->left!=NULL&&node->right!=NULL){
            State stateLeft = dfs(node->left);
            State stateRight = dfs(node->right);
            //stateNow.states[0] = min(stateNow.states[0],stateLeft.states[0]+stateRight.states[0]);
            stateNow.states[3] = min(stateNow.states[3],stateLeft.states[0]+stateRight.states[1]);
            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[0]+stateRight.states[2]);
            stateNow.states[3] = min(stateNow.states[3],stateLeft.states[0]+stateRight.states[2]);
            stateNow.states[3] = min(stateNow.states[3],stateLeft.states[0]+stateRight.states[3]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[1]+stateRight.states[1]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[1]+stateRight.states[2]);
            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[1]+stateRight.states[3]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[1]+stateRight.states[3]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[2]+stateRight.states[2]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[2]+stateRight.states[3]);
            stateNow.states[1] = min(stateNow.states[1],stateLeft.states[3]+stateRight.states[3]);
            stateNow.states[2] = min(stateNow.states[2],stateLeft.states[3]+stateRight.states[3]);

            //stateNow.states[0] = min(stateNow.states[0],stateRight.states[0]+stateLeft.states[0]);
            stateNow.states[3] = min(stateNow.states[3],stateRight.states[0]+stateLeft.states[1]);
            stateNow.states[1] = min(stateNow.states[1],stateRight.states[0]+stateLeft.states[2]);
            stateNow.states[3] = min(stateNow.states[3],stateRight.states[0]+stateLeft.states[2]);
            stateNow.states[3] = min(stateNow.states[3],stateRight.states[0]+stateLeft.states[3]);
            //stateNow.states[1] = min(stateNow.states[1],stateRight.states[1]+stateLeft.states[1]);
            stateNow.states[2] = min(stateNow.states[2],stateRight.states[1]+stateLeft.states[2]);
            stateNow.states[1] = min(stateNow.states[1],stateRight.states[1]+stateLeft.states[3]);
            stateNow.states[2] = min(stateNow.states[2],stateRight.states[1]+stateLeft.states[3]);
            //stateNow.states[2] = min(stateNow.states[2],stateRight.states[2]+stateLeft.states[2]);
            stateNow.states[2] = min(stateNow.states[2],stateRight.states[2]+stateLeft.states[3]);
            //stateNow.states[1] = min(stateNow.states[1],stateRight.states[3]+stateLeft.states[3]);
            //stateNow.states[2] = min(stateNow.states[2],stateRight.states[3]+stateLeft.states[3]);
            stateNow.states[3] = min(stateNow.states[3],stateNow.states[1]);
        }
        else if(node->left!=NULL){
            State stateLeft = dfs(node->left);
            stateNow.states[0] = stateLeft.states[0];
            stateNow.states[1] = INFINITY;
            stateNow.states[2] = stateLeft.states[2];
            stateNow.states[3] = stateLeft.states[3];
        }
        else if(node->right!=NULL){
            State stateRight = dfs(node->right);
            stateNow.states[0] = stateRight.states[0];
            stateNow.states[1] = INFINITY;
            stateNow.states[2] = stateRight.states[2];
            stateNow.states[3] = stateRight.states[3];
        }


        cout<<node->val << ":state:" << stateNow.states[0] << "," << stateNow.states[1] << "," << stateNow.states[2]<<","<<stateNow.states[3]<<endl;
        return stateNow;
    }
public:
    int navigation(TreeNode* root) {
        State state = dfs(root);
        int ans = INFINITY;
        ans = min(ans,state.states[1]);
        ans = min(ans,state.states[2]);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     // TreeNode* root = new TreeNode(1);
//     // root->left=new TreeNode(2);
//     // root->left->left = new TreeNode(3);
//     // root->left->right = new TreeNode(4);

//     // TreeNode *root = new TreeNode(1);
//     // root->left = new TreeNode(2);
//     // root->right = new TreeNode(3);
//     // root->left->left = new TreeNode(4);
//     // root->left->left->left = new TreeNode(8);
//     // root->left->left->right = new TreeNode(9);
//     // root->right->left = new TreeNode(6);
//     // root->right->right = new TreeNode(7);

//     vector<int> tree = {
//         //1,null,2,3,4,5,null,6,null,null,7,null,8,9,10,null,11,12,13,14,15,16,17,18
//         1,null,2,3,4,5,null,6,7,null,8,9,null,null,10,11,12,13,14,15,16,17,18,null,19,null,20,null,21,22,23,24,25,null,26,27,null,null,28,null,29,30,31,null,32,null,33,null,34,35,null,36,37,null,38,null,39,null,40,null,41,null,42,43,44,45,46,47,48,49
//     };
//     TreeNode *root = GetTree(tree);

//     int ans = solution.navigation(root);

//     return 0;
// }
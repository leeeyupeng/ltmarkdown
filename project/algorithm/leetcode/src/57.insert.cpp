#include"leetcode.h"

class SegmentTree{
public:
    struct TreeNode{
        int l,r;
        bool flag;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int _l,int _r):l(_l),r(_r),flag(false),left(nullptr),right(nullptr){}
    };
    TreeNode* root;
public:
    void init(int l,int r){
        root = new TreeNode(l,r);
    }
    void _add(TreeNode* node,int l,int r){
        if(node->flag == true){return ;}
        if(node->l == l&& node->r == r){node->flag = true;return ;}
        int mid = (node->l+node->r)>>1;
        if(node->l == mid){
            if(node->left == nullptr){node->left = new TreeNode(node->l,mid);}
            _add(node->left,l,min(mid,r));
            return;
        }
        if(l<mid){
            if(node->left == nullptr){node->left = new TreeNode(node->l,mid);}
            _add(node->left,l,min(mid,r));
        }
        if(r>=mid){
            if(node->right == nullptr){node->right = new TreeNode(mid,node->r);}
            _add(node->right,max(mid,l),r);
        }
        if(node->left!=nullptr && node->right!=nullptr){
            node->flag = node->left->flag && node->right->flag;
        }
    }
    void add(int l,int r){
        _add(root,l,r);
    }

    TreeNode* getroot(){return root;}

    void _getintervals(TreeNode* node,vector<vector<int>>& intervals){
        if(node==nullptr){return;}
        if(node->flag==true){
            if(!intervals.empty() && intervals.back()[1] == node->l){
                intervals.back()[1] = node->r;
            }
            else{
                intervals.push_back({node->l,node->r});
            }
            return;
        }
        _getintervals(node->left,intervals);
        _getintervals(node->right,intervals);

    }
    void getintervals(vector<vector<int>>& intervals){
        _getintervals(root,intervals);
    }
};
class Solution {
private:
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervalmin=newInterval[0],intervalmax=newInterval[1];
        int n = intervals.size();
        if(n==0){return vector<vector<int>>(1,newInterval);}
        for(int i = 0; i < n; i ++){
            intervalmin = min(intervalmin,intervals[i][0]);
            intervalmax = max(intervalmax,intervals[i][1]);
        }

        SegmentTree st;
        st.init(intervalmin,intervalmax+1);
        for(int i = 0; i < n; i ++){
            st.add(intervals[i][0],intervals[i][1]);
        }
        st.add(newInterval[0],newInterval[1]);

        vector<vector<int>> ans;
        st.getintervals(ans);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> intervals={
// {8,10}
//     };
//     vector<int> newInterval={
//         11,11
//     };
//     vector<vector<int>> ans = solution.insert(intervals,newInterval);
//     return 0;
// }
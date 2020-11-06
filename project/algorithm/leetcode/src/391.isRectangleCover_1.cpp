#include"leetcode.h"

class SegmentTree{
    struct TreeNode{
        int val;
        bool flag;
        int l;
        int r;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int _val,int _l,int _r):val(_val),flag(false),l(_l),r(_r),left(nullptr),right(nullptr){}
    };
    TreeNode* stree;
public:
    void buildtree(int l,int r){
        stree = new TreeNode(0,l,r);        
    }
    bool add(TreeNode* node,int a,int b){
        if(a==b){return true;}
        if(node->flag == true){return false;}
        if(node->l == node->r - 1){
            if(node->flag == true){return false;}
            node->flag = true;
            return true;
        }
        if(node->l == a && node->r == b){
            if(node->val != 0 ||  node->flag == true){return false;}
            node->flag = true;
            return true;
        }
        int mid = (node->l + node->r)>>1;
        int ans = true;
        if(a<mid){
            if(node->left == nullptr){
                node->left = new TreeNode(0,node->l,(node->l + node->r)>>1);
            }
            ans&=add(node->left,a,min(mid,b));
        }
        if(b>mid){
            if(node->right == nullptr){
                node->right = new TreeNode(0,(node->l + node->r)>>1,node->r);
            }
            ans&=add(node->right,max(mid,a),b);
        }
        node->val += b-a;
        return ans;
    }
    bool add(int a, int b){
        return add(stree,a,b);
    }
    void del(TreeNode* node,int a,int b){
        if(a==b){return;}
        if(node->l == node->r - 1){
            node->flag = false;
            return;
        }
        if(node->l == a&&node->r == b && node->flag == true){
            node->flag = false;
            return;
        }
        int mid = (node->l + node->r)>>1;
        if(a<mid){
            del(node->left,a,min(mid,b));
        }
        if(b>mid){
            del(node->right,max(mid,a),b);
        }
        node->val -= b-a;
    }
    void del(int a,int b){
        del(stree,a,b);
    }
};
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int> minysort(n);
        for(int i = 0; i < n; i ++){
            minysort[i] = i;
        }
        sort(minysort.begin(),minysort.end(),[&rectangles](int a,int b){
            if(rectangles[a][1] == rectangles[b][1]){
                return rectangles[a][0] < rectangles[b][0];
            }
            return rectangles[a][1] < rectangles[b][1];
        });
        vector<int> maxysort(n);
        for(int i = 0; i < n; i ++){
            maxysort[i] = i;
        }
        sort(maxysort.begin(),maxysort.end(),[&rectangles](int a,int b){
            if(rectangles[a][3] == rectangles[b][3]){
                return rectangles[a][0] < rectangles[b][0];
            }
            return rectangles[a][3] < rectangles[b][3];
        });
        long long areasums=0;
        vector<int> maxrect=rectangles[0];
        for(int i = 0;i < n; i ++){
            areasums+=(rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            maxrect[0] = min(maxrect[0],rectangles[i][0]);
            maxrect[1] = min(maxrect[1],rectangles[i][1]);
            maxrect[2] = max(maxrect[2],rectangles[i][2]);
            maxrect[3] = max(maxrect[3],rectangles[i][3]);
        }
        if(areasums != (maxrect[2] - maxrect[0])*(maxrect[3] - maxrect[1])){return false;}
        int i = 0,j = 0;
        SegmentTree stree;
        stree.buildtree(maxrect[0],maxrect[2]);
        while(i<n){
            if(rectangles[minysort[i]][1] < rectangles[maxysort[j]][3]){
                bool success = stree.add(rectangles[minysort[i]][0],rectangles[minysort[i]][2]);
                if(success == false){return success;}
                i++;
            }
            else{
                stree.del(rectangles[maxysort[j]][0],rectangles[maxysort[j]][2]);
                j++;
            }
        }
        return true;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> rectangles={
// {0,0,3,1},{0,1,2,3},{1,0,2,1},{2,2,3,3}
//  };
//     bool ans = solution.isRectangleCover(rectangles);
//     return 0;
// }
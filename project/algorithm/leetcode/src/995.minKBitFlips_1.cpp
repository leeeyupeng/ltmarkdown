#include"leetcode.h"

class SegmentTree{
private:
    struct Node{
        int val,lval,rval;
        int counter;
        Node* left;
        Node* right;
        Node():val(0),lval(0),rval(0),counter(0),left(nullptr),right(nullptr){}
    };
    Node* root;
    void _add(Node* node,int l,int r){
        if(node->lval==l && node->rval==r){
            node->counter++;
            return;
        }
        if(node->lval == node->val){return;}

        if(l<node->val){
            if(node->left==nullptr){
                node->left=new Node();
                node->left->lval = node->lval;
                node->left->rval = node->val;
                node->left->val = (node->left->lval + node->left->rval)>>1;
                node->left->counter=0;
            }
            _add(node->left,l,min(node->val,r));
        }
        if(r>node->val){
            if(node->right==nullptr){
                node->right=new Node();
                node->right->lval = node->val;
                node->right->rval = node->rval;
                node->right->val = (node->right->lval + node->right->rval)>>1;
                node->right->counter=0;
            }
            _add(node->right,max(l,node->val),r);
        }
    }

    int _getcounter(Node* node,int index){
        if(node==nullptr){return 0;}        
        int ret = 0;
        if(node->lval <= index && index<node->rval){ret+=node->counter;}
        if(node->lval == node->val){
            return ret;
        }
        if(index<node->val){
            ret+=_getcounter(node->left,index);
        }
        else{
            ret+=_getcounter(node->right,index);
        }
        return ret;
    }
public:
    SegmentTree(int _n){
        root=new Node();
        root->lval=0;
        root->rval=_n;
        root->val = (root->lval + root->rval)>>1;
        root->counter=0;
    }

    void add(int l,int r){
        _add(root,l,r);
    }
    int getcounter(int index){
        return _getcounter(root,index);
    }
};
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        SegmentTree st(n);
        int ret = 0;
        int counter = 0;
        for(int i = 0; i <= n-K;i++){
            counter = st.getcounter(i);
            if(A[i] == 0 && ((counter&0x1) == 0x0)){
                st.add(i,i+K);
                ret++;
            }
            else if(A[i]==1 && ((counter&0x1) == 0x1)){
                st.add(i,i+K);
                ret++;
            }
        }
        for(int i = n-K;i<n;i++){
            counter = st.getcounter(i);
            if(A[i] == 0 && ((counter&0x1) == 0x0)){
                return -1;
            }
            else if(A[i]==1 && ((counter&0x1) == 0x1)){
                return -1;
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> A={
//         0,0,0,1,0,1,1,0
//     };
//     int K = 3;
//     auto ret = solution.minKBitFlips(A,K);
//     return -1;
// }
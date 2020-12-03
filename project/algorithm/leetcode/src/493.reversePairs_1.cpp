#include"leetcode.h"

namespace tree{
    enum Color : char
    {
        Black,
        Red,
    };
    template<typename T>
    struct RedBlackTreeNode{
        T val;
        int count;
        int sums;
        Color color;
        
        
        RedBlackTreeNode *left;
        RedBlackTreeNode *right;

        RedBlackTreeNode(T _val):val(_val),count(0),sums(0),color(Color::Red),left(nullptr),right(nullptr){}
    };
    template<typename T>
    class RedBlackTree{
    private:
        RedBlackTreeNode<T> *root=nullptr;
        void _left_rotate(RedBlackTreeNode<T>* &node);
        void _right_rotate(RedBlackTreeNode<T>* &node);
        void _insert(RedBlackTreeNode<T>* &grand,RedBlackTreeNode<T>* &parent,RedBlackTreeNode<T>* &node,T value);
        int _uppersums(T value,RedBlackTreeNode<T>* node);
    public:
        void insert(T value);
        int uppersums(T value);
        int size();
    };
    template<typename T>
    void RedBlackTree<T>::_left_rotate(RedBlackTreeNode<T>* &node){
        RedBlackTreeNode<T>* right = node->right;
        node->right = right->left;
        right->left = node;

        right->sums = node->sums;
        if(node!=nullptr){
            node->sums = node->count;
            if(node->left!=nullptr){
                node->sums += node->left->sums;
            }
            if(node->right!=nullptr){
                node->sums += node->right->sums;
            }
        }
        node = right;
    }
    template<typename T>
    void RedBlackTree<T>::_right_rotate(RedBlackTreeNode<T>* &node){
        RedBlackTreeNode<T>* left = node->left;
        node->left = left->right;
        left->right = node;

        left->sums = node->sums;
        if(node!=nullptr){
            node->sums = node->count;
            if(node->left!=nullptr){
                node->sums += node->left->sums;
            }
            if(node->right!=nullptr){
                node->sums += node->right->sums;
            }
        }

        node = left;
    }
    template<typename T>
    void RedBlackTree<T>::_insert(RedBlackTreeNode<T>* &grand,RedBlackTreeNode<T>* &parent,RedBlackTreeNode<T>* &node,T value){
        if(node==nullptr){
            node = new RedBlackTreeNode<T>(value);
            node->count=1;
            node->sums = 1;
            return;
        }
        else if(node->val>value){
            _insert(parent,node,node->left,value);
        }
        else if(node->val<value){
            _insert(parent,node,node->right,value);
        }
        else{
            node->count ++;
            node->sums ++;
            return;
        }

        if(node!=nullptr){
            node->sums = node->count;
            if(node->left!=nullptr){
                node->sums += node->left->sums;
            }
            if(node->right!=nullptr){
                node->sums += node->right->sums;
            }
        }
        
        if(parent == nullptr){
            node->color = Color::Black;
        }        
        else if(parent->color==Color::Black){
            
        }
        else if(parent->color!=node->color){
            
        }
        else if(parent == node){

        }
        else{
            RedBlackTreeNode<T>* uncle;
            if(grand->left == parent){
                uncle = grand->right;
                if(uncle != nullptr && uncle->color == Color::Red){
                    parent->color = Color::Black;
                    uncle->color = Color::Black;
                    grand->color = Color::Red;
                }
                else{
                    if(parent->left == node){
                        _right_rotate(grand);
                        grand->color=Color::Black;
                        grand->right->color=Color::Red;
                    }
                    else{
                        _left_rotate(parent);
                        _right_rotate(grand);
                        grand->color=Color::Black;
                        grand->right->color = Color::Red;
                    }
                }
            }
            else{
                uncle = grand->left;
                if(uncle != nullptr && uncle->color == Color::Red){
                    parent->color = Color::Black;
                    uncle->color = Color::Black;
                    grand->color = Color::Red;
                }
                else{
                    if(parent->right == node){
                        _left_rotate(grand);
                        grand->color=Color::Black;
                        grand->left->color=Color::Red;
                    }
                    else{
                        _right_rotate(parent);
                        _left_rotate(grand);
                        grand->color=Color::Black;
                        grand->left->color = Color::Red;
                    }
                }
            }
        }

    }
    template<typename T>
    void RedBlackTree<T>::insert(T value){
        RedBlackTreeNode<T>* grand = nullptr;
        RedBlackTreeNode<T>* parent = nullptr;
        _insert(grand,parent,root,value);
    }

    template<typename T>
    int RedBlackTree<T>::_uppersums(T value,RedBlackTreeNode<T>* node){
        int sums = 0;
        if(node==nullptr){
            return sums;
        }
        if(node->val <= value){
            sums = _uppersums(value,node->right);
        }
        else{
            sums = _uppersums(value,node->left);
            sums += node->count;
            if(node->right != nullptr){
                sums += node->right->sums;
            }
        }
        return sums;
    }
    template<typename T>
    int RedBlackTree<T>::uppersums(T value){
        return _uppersums(value,root);
    }    
    template<typename T>
    int RedBlackTree<T>::size(){
        if(root == nullptr){
            return 0;
        }
        return root->sums;
    }    
}
using namespace tree;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int ans = 0;
        RedBlackTree<int> rbtree;
        long long d;
        for(int i = 0; i < n; i ++){
            d = (long long)nums[i];
            d = d*2;
            if(d>=INT_MAX){
                
            }
            else if(d<INT_MIN){
                ans += rbtree.size();
            }
            else{
                ans += rbtree.uppersums((int)d);
            }
            rbtree.insert(nums[i]);
        }
        return ans;
    }
};
// int main(){
//     vector<int> nums = {
// 2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647
// };
//     Solution solution;
//     int ans = solution.reversePairs(nums);

//     return 0;
// }
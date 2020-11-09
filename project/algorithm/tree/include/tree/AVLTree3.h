#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
namespace tree{
    template<typename T>
    struct AVLTreeNode{
        T val;
        int height;
        AVLTreeNode* left;
        AVLTreeNode* right;
        AVLTreeNode(T _val):val(_val),height(1),left(nullptr),right(nullptr){}
    };

    template<typename T>
    class AVLTree
    {
    private:
        /* data */
        AVLTreeNode<T>* root;

        inline int get_height(AVLTreeNode<T>* node);
        inline int get_balance_factor(AVLTreeNode<T>* node);
        AVLTreeNode<T>* _balance(AVLTreeNode<T>* node);
        AVLTreeNode<T>* left_rotate(AVLTreeNode<T>* node);
        AVLTreeNode<T>* right_rotate(AVLTreeNode<T>* node);
        AVLTreeNode<T>* _insert(AVLTreeNode<T>* node,T val);
        AVLTreeNode<T>* _remove(AVLTreeNode<T>* node,T val);
        bool _isbalance(AVLTreeNode<T>* node);
    public:
        AVLTree();
        ~AVLTree();

        void insert(T val);
        void remove(T val);
        bool find(T val);
        bool isbalance();
    };
    template<typename T>
    inline int AVLTree<T>::get_height(AVLTreeNode<T>* node){
        if(node==nullptr){return 0;}
        return node->height;
    }
    template<typename T>
    inline int AVLTree<T>::get_balance_factor(AVLTreeNode<T>* node){
        if(node==nullptr){return 0;}
        return get_height(node->right) - get_height(node->left);
    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::_balance(AVLTreeNode<T>* node){
        int bf = get_balance_factor(node);
        if(bf>1){
            if(get_balance_factor(node->right)>=0){
                node = left_rotate(node);
            }
            else{
                node->right = right_rotate(node->right);
                node = left_rotate(node);
            }
        }
        else if(bf<-1){
            if(get_balance_factor(node->left)<=0){
                node = right_rotate(node);
            }
            else{
                node->left = left_rotate(node->left);
                node = right_rotate(node);
            }
        }
        return node;
    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::left_rotate(AVLTreeNode<T>* node){
        AVLTreeNode<T>* right=node->right;
        node->right = right->left;
        right->left = node;
        node->height = max(get_height(node->left),get_height(node->right)) + 1;
        right->height = max(get_height(right->left),get_height(right->right)) + 1;
        return right;
    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::right_rotate(AVLTreeNode<T>* node){
        AVLTreeNode<T>* left = node->left;
        node->left = left->right;
        left->right = node;
        node->height = max(get_height(node->left),get_height(node->right)) + 1;
        left->height = max(get_height(left->left),get_height(left->right)) + 1;
        return left;
    }
    template<typename T>
    AVLTree<T>::AVLTree()
    {
        root=nullptr;
    }
    template<typename T>
    AVLTree<T>::~AVLTree()
    {
    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::_insert(AVLTreeNode<T>* node,T val){
        if(node==nullptr){
            node = new AVLTreeNode(val);
            return node;
        }
        else if(node->val == val){
            return node;
        }
        else if(node->val>val){
            node->left = _insert(node->left,val);
        }
        else if(node->val<val){
            node->right = _insert(node->right,val);
        }
        node->height = max(get_height(node->left),get_height(node->right)) + 1;
        node = _balance(node);
        return node;
    }
    template<typename T>
    void AVLTree<T>::insert(T val)
    {
        root = _insert(root,val);
    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::_remove(AVLTreeNode<T>* node,T val){
        if(node==nullptr){return node;}
        AVLTreeNode<T>* retnode=nullptr;
        if(node->val==val){
            if(node->left==nullptr&&node->right==nullptr){
                retnode=nullptr;
            }
            else if(node->left==nullptr){
                retnode = node->right;
                node->right=nullptr;
                //retnode = node;
            }
            else if(node->right == nullptr){
                retnode = node->left;
                node->left=nullptr;
                //retnode = node;
            }
            else{
                if(get_balance_factor(node)>0){
                    retnode = left_rotate(node);
                    retnode->left = _remove(node,val);
                }
                else{
                    retnode = right_rotate(node);
                    retnode->right = _remove(node,val);
                }
                //retnode = node;
            }            
        }
        else if(node->val>val){
            node->left=_remove(node->left,val);
            retnode = node;
        }
        else if(node->val<val){
            node->right=_remove(node->right,val);
            retnode = node;
        }
        if(retnode==nullptr){return retnode;}
        retnode->height = max(get_height(retnode->left),get_height(retnode->right)) + 1;
        retnode = _balance(retnode);
        int bf = get_balance_factor(retnode);
        if(bf<-1||bf>1){
            cout<<"error bf<-1||bf>1"<<endl;
        }

        return retnode;
    }
    template<typename T>
    void AVLTree<T>::remove(T val)
    {
        root = _remove(root,val);
    }

    template<typename T>
    bool AVLTree<T>::find(T val)
    {
        AVLTreeNode<T>* node = root;
        while(node!=nullptr){
            if(node->val == val){return true;}
            else if(node->val>val){node = node->left;}
            else if(node->val<val){node=node->right;}
        }
        return false;
    }
    template<typename T>
    bool AVLTree<T>::_isbalance(AVLTreeNode<T>* node){
        if(node==nullptr){return true;}
        bool isbalance = true;
        isbalance &= _isbalance(node->left);
        if(isbalance==false){return isbalance;}
        isbalance &= _isbalance(node->right);
        if(isbalance==false){return isbalance;}
        int height = max(get_height(node->left),get_height(node->right)) + 1;
        if(height!=node->height){
            cout<<"error:height!=node->height"<<endl;
            return false;
        }
        int bf = get_balance_factor(node);
        if(bf<-1||bf>1){
            cout<<"error:bf<-1||bf>1"<<endl;
            return false;
        }
        return isbalance;
    }
    template<typename T>
    bool AVLTree<T>::isbalance(){
        return _isbalance(root);
    }
}
#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
namespace tree{
    enum Color : char
    {
        Black,
        Red,
    };
    template<typename T>
    struct RedBlackTreeNode{
        T val;
        Color color;
        
        RedBlackTreeNode *left;
        RedBlackTreeNode *right;

        RedBlackTreeNode(T _val):val(_val),color(Color::Red),left(nullptr),right(nullptr){}
    };
    template<typename T>
    class RedBlackTree{
    private:
        RedBlackTreeNode<T> *root=nullptr;
        void _left_rotate(RedBlackTreeNode<T>* &node);
        void _right_rotate(RedBlackTreeNode<T>* &node);
        void _insert(RedBlackTreeNode<T>* &grand,RedBlackTreeNode<T>* &parent,RedBlackTreeNode<T>* &node,T value);
        bool _check(RedBlackTreeNode<T>* node,int black_height);
    public:
        void insert(T value);
        bool find(T val);
        bool check();
    };
    template<typename T>
    void RedBlackTree<T>::_left_rotate(RedBlackTreeNode<T>* &node){
        RedBlackTreeNode<T>* right = node->right;
        node->right = right->left;
        right->left = node;
        node = right;
    }
    template<typename T>
    void RedBlackTree<T>::_right_rotate(RedBlackTreeNode<T>* &node){
        RedBlackTreeNode<T>* left = node->left;
        node->left = left->right;
        left->right = node;
        node = left;
    }
    template<typename T>
    void RedBlackTree<T>::_insert(RedBlackTreeNode<T>* &grand,RedBlackTreeNode<T>* &parent,RedBlackTreeNode<T>* &node,T value){
        if(node==nullptr){
            node = new RedBlackTreeNode<T>(value);
        }
        else if(node->val>value){
            _insert(parent,node,node->left,value);
        }
        else if(node->val<value){
            _insert(parent,node,node->right,value);
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
    bool RedBlackTree<T>::find(T val)
    {
        RedBlackTreeNode<T>* node = root;
        while(node!=nullptr){
            if(node->val == val){return true;}
            else if(node->val>val){node = node->left;}
            else if(node->val<val){node=node->right;}
        }
        return false;
    }
    template<typename T>
    bool RedBlackTree<T>::_check(RedBlackTreeNode<T>* node,int black_height){
        if(node==nullptr){
            black_height = 1;
            return true;
        }
        int left_black_height=0;
        bool flag = true;
        if(node->color==Color::Red){
            if(node->left!=nullptr && node->left->color==Color::Red){
                flag=false;
            }
            if(node->right!=nullptr && node->right->color==Color::Red){
                flag=false;
            }
            if(flag==false){
                return flag;
            }
        }
        flag = flag&&_check(node->left,left_black_height);
        if(flag==false){
            return flag;
        }
        int right_black_height=0;
        flag = flag&&_check(node->right,right_black_height);
        if(flag==false){
            return flag;
        }
        if(left_black_height!=right_black_height){
            flag = flag&&false;
        }
        if(flag==false){
            return flag;
        }
        black_height = left_black_height + node->color==Color::Black?1:0;
        return flag;
    }
    template<typename T>
    bool RedBlackTree<T>::check(){
        int black_height=0;
        return _check(root,black_height);
    }
}
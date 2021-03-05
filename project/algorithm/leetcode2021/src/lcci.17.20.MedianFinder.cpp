#include"leetcode.h"

template<typename T>
class AVLTree{
private:
    struct Node
    {
        T value;
        int nums;
        int counter;
        int height;
        Node* left;
        Node* right;
        Node(T _value):value(_value),nums(1),counter(1),height(1),left(nullptr),right(nullptr){}
    };
    
    Node* root=nullptr;
    inline int _getheight(Node* node){
        if(node==nullptr){return 0;}
        return node->height;
    }
    inline int _getcounter(Node* node){
        if(node==nullptr){return 0;}
        return node->counter;
    }
    void _rotate_left(Node* &node){
        Node* right = node->right;
        node->right = right->left;
        node->height = max(_getheight(node->left),_getheight(node->right)) + 1;
        node->counter = node->nums + _getcounter(node->left) + _getcounter(node->right);
        right->left = node;
        node=right;
        node->height = max(_getheight(node->left),_getheight(node->right)) + 1;
        node->counter = node->nums + _getcounter(node->left) + _getcounter(node->right);
    }
    void _rotate_right(Node* &node){
        Node* left = node->left;
        node->left = left->right;
        node->height = max(_getheight(node->left),_getheight(node->right)) + 1;
        node->counter = node->nums + _getcounter(node->left) + _getcounter(node->right);
        left->right = node;
        node=left;
        node->height = max(_getheight(node->left),_getheight(node->right)) + 1;
        node->counter = node->nums + _getcounter(node->left) + _getcounter(node->right);
    }
    Node* _insert(Node* node,T e){
        if(node==nullptr){node = new Node(e);return node;}
        else if(node->value == e){node->nums++;node->counter++;return node;}
        else if(node->value > e){
            node->left= _insert(node->left,e);            
        }
        else{
            node->right= _insert(node->right,e);
        }
        node = _balance(node);
        return node;
    }

    Node* _remove(Node* node,T e){
        if(node->value == e){
            if(node->nums == 1){
                if(node->left == nullptr && node->right == nullptr){delete node;node = nullptr;return node;}
                else if(_getheight(node->left) >= _getheight(node->right)){
                    _rotate_right(node);
                    node->right=_remove(node->right,e);
                }
                else{
                    _rotate_left(node);
                    node->left = _remove(node->left,e);
                }
            }
            else{
                node->nums --;
            }
        }
        else if(node->value > e){
            node->left = _remove(node->left,e);
        }
        else if(node->value < e){
            node->right = _remove(node->right,e);
        }

        node = _balance(node);
        return node;
    }

    Node* _balance(Node* node){
        if(node == nullptr){return node;}
        if(_getheight(node->left) - _getheight(node->right) >= 2){
            if(_getheight(node->left->left) >= _getheight(node->left->right)){
                _rotate_right(node);
            }
            else{
                _rotate_left(node->left);
                _rotate_right(node);
            }
        }
        else if(_getheight(node->left) - _getheight(node->right) <= -2){
            if(_getheight(node->right->right) >= _getheight(node->right->left)){
                _rotate_left(node);
            }
            else{
                _rotate_right(node->right);
                _rotate_left(node);
            }
        }
        else{
            node->height = max(_getheight(node->left),_getheight(node->right)) + 1;
            node->counter = node->nums + _getcounter(node->left) + _getcounter(node->right);
        }
        return node;
    }

    T _getk(Node* node,int k){
        if(_getcounter(node->left) >= k){
            return _getk(node->left,k);
        }
        else if(_getcounter(node->left) + node->nums >= k) {
            return node->value;
        }
        else{
            return _getk(node->right,k - (_getcounter(node->left) + node->nums));
        }
    }
public:
    void insert(T e){
        root = _insert(root,e);
    }
    void remove(T e){
        root = _remove(root,e);
    }

    T getk(int k){
        return _getk(root,k);
    }
};

class MedianFinder {
private:
    AVLTree<int> avl;
    int n;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        avl.insert(num);
        n++;
    }
    
    double findMedian() {
        double ret;
        int k = n;
        if((k & 0x1) == 0x1){
            ret=avl.getk((k>>1) + 1);
        }
        else{
            long long llret = avl.getk(k>>1);
            llret += avl.getk((k>>1) + 1);
            ret =llret / (double)2;
        }
        return ret;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
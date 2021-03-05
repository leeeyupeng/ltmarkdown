#include<iostream>
#include<algorithm>
using namespace std;

namespace tree{



    template<typename T>
    class RedBlackTree
    {
    private:
        enum Color : char
        {
            Black,
            Red,
        };
        struct Node
        {
            T val;
            Color color;
            int sums;
            Node* parent;
            Node* left;
            Node* right;
            Node(T _val):val(_val),color(Color::Red),sums(1),parent(nullptr),left(nullptr).right(nullptr){}
        };
        Node* root;

        inline node* _getparent(T value){
            Node* parent=root;
            Node* node = parent;
            while(node!=nullptr){
                parent = node;
                if(node->val >= value){
                    node = node->left;
                }
                else{
                    node = node->right;
                }
            }
            return parent;
        }
        void _left_rotate(Node* &node){
            Node* parent = node->parent;
            Node* left = node->left;
            Node* right = node->right;
            node->right = right->left;
            right->left = left;
            node = right;
        }
        void _right_rotate(Node* &node){

        }
        void _blacktored(Node* node){            
            node* parent = node->parent;
            if(parent == null){return;}
            node->color = Color::Red;
            if(parent->color==Color::Black){return;}
            node* grand = parent->parent;
            Node* uncle;
            if(grand->left == parent){uncle = grand->right;}
            else{uncle = grand->left;}
            parent->color = Color::Black;
            if(uncle==nullptr){}
            else if(uncle->color==Color::Red){
                uncle->color = Color::Black;
            }
            _blacktored(grand);
        }
        void _clear(Node* &node){
            if(node!=nullptr){
                _clear(node->left);
                _clear(node->right);
                delete node;
                node=nullptr;
            }
        }
    public:
        RedBlackTree();
        ~RedBlackTree(){

        }
        void insert(T value){
            if(root==nullptr){
                root = new Node(value);
                root->color = Color::Black;
            }
            Node* parent = getparent(value);
            Node* node = new Node(value);
            node->parent = parent;
            if(parent->color==Color::Black){
                if(parent->val>value){
                    parent->left = node;                    
                }
                else{
                    parent->right = node;
                }                
            }
            else{
                Node* grand = parent->parent;
                Node* uncle;
                if(grand->left == parent){uncle = grand->right;}
                else{uncle = grand->left;}
                if(uncle == nullptr){

                }
                else if(uncle->color == Color::Red){
                    parent->color = Color::Black;
                    uncle->color = Color::Black;
                    _blacktored(grand);
                }
            }
        }
        void remove(T value){

        }
        void clear(){
            _clear(root);
            root = nullptr;
        }
        T getindex(int index){

        }
    };    
}
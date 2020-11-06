#pragma once
namespace tree{
    template<typename T>
    class BinarySearchTree{
        struct TreeNode{
            T val;
            TreeNode* left;
            TreeNode* right;
            TreeNode(T _val):val(_val),left(NULL),right(NULL){}
        };

        TreeNode* root;
    public:
        BinarySearchTree(){
            root = NULL;
        }
        void insert(T value){
            if(root == NULL){root = new TreeNode(value);return;}
            TreeNode* parent = NULL;
            TreeNode* node = root;
            while(node!=NULL){
                parent = node;
                if(node->val>value){node = node->left;}
                else{node = node->right;}
            }
            if(parent->val>value){parent->left = new TreeNode(value);}
            else{parent->right = new TreeNode(value);}
        }
        void remove(T value){
            TreeNode* parent = NULL;
            TreeNode* node = root;
            while(node!=NULL&&node->val!=value){
                parent = node;
                if(node->val>value){node = node->left;}
                else{node = node->right;}
            }
            if(node==NULL){return;}
            if(parent == NULL && node->val == value){delete root;root = NULL;}
            if(node!=NULL && node->val == value){
                TreeNode* childright = node->right;

                if(childright!=NULL){
                    while(childright->left!=NULL){
                        childright=childright->left;
                    }
                    childright->left = node->left;

                    if(parent->left == node){
                        parent->left = node->right;
                    }
                    else{
                        parent->right = node->right;
                    }
                }
                else{
                    if(parent->left == node){
                        parent->left = node->left;
                    }
                    else{
                        parent->right = node->left;
                    }
                }
                delete node;
            }
        }
        bool find(T value){
            TreeNode* parent = NULL;
            TreeNode* node = root;
            while(node!=NULL&&node->val!=value){
                parent = node;
                if(node->val>value){node = node->left;}
                else{node = node->right;}
            }
            if(node==NULL){return false;}
            if(node->val == value){return true;}
            else{return false;}
        }
        TreeNode* _get(TreeNode* node,int index,int &counter){
            if(node==NULL){return NULL;}
            TreeNode* temp = _get(node->left,index,counter);
            if(temp!=NULL){return temp;}        
            if(index == counter){return node;}  
            counter++;      
            temp = _get(node->right,index,counter);
            if(temp!=NULL){return temp;}
            return NULL;
        }
        T get(int index){
            int counter = 0;
            TreeNode* node = _get(root,index,counter);
            if(node!=NULL){return node->val;}
            return T(0);
        }
    };
}
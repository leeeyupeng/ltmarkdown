namespace tree{
    template<typename T>
    struct AVLTreeNode{
        T val;
        int height;
        AVLTreeNode* left;
        AVLTreeNode* right;
        AVLTreeNode(T _val):val(_val),height(0),left(nullptr),right(nullptr){}
    };

    template<typename T>
    class AVLTree
    {
    private:
        /* data */
        AVLTreeNode<T>* left_rotate(AVLTreeNode<T>* node);
        AVLTreeNode<T>* right_rotate(AVLTreeNode<T>* node);
    public:
        AVLTree(/* args */);
        ~AVLTree();
        void insert(T val);
        void remove(T val);
        bool find(T val);
    };
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::left_rotate(AVLTreeNode<T>* node){

    }
    template<typename T>
    AVLTreeNode<T>* AVLTree<T>::right_rotate(AVLTreeNode<T>* node){

    }
    template<typename T>
    AVLTree<T>::AVLTree(/* args */)
    {
    }
    template<typename T>
    AVLTree<T>::~AVLTree()
    {
    }

    template<typename T>
    void AVLTree<T>::insert(T val)
    {
    }
    template<typename T>
    void AVLTree<T>::remove(T val)
    {
    }

    template<typename T>
    bool AVLTree<T>::find(T val)
    {
    }
}
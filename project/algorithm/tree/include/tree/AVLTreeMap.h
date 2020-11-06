namespace  tree
{
    template<typename Key,typename Value>
    struct AVLTreeMapNode
    {
        Key key;
        Value value;
        int height;
        AVLTreeMapNode* left;
        AVLTreeMapNode* right;
        AVLTreeMapNode(Key _key,Value _value):key(_key),value(_value),height(0),left(nullptr),right(nullptr){}
    };
    
    template<typename Key,typename Value>
    class AVLTreeMap{
        private:
            /* data */
            AVLTreeMapNode<Key,Value>* left_rotate(AVLTreeMapNode<Key,Value>* node);
            AVLTreeMapNode<Key,Value>* right_rotate(AVLTreeMapNode<Key,Value>* node);
        public:
            AVLTreeMap(/* args */);
            ~AVLTreeMap();
            void insert(Key key,Value value);
            void remove(Key key);
            AVLTreeMapNode* find(Key key);
            Value get(Key key);
    };
} // namespace  tree

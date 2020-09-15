namespace lt {
	namespace tree
	{
		//BinaryIndexedTree
		class BITree {
		private:
			int n;
			int* _arr;
		public:
			BITree();
			~BITree();
			void init(int n);
			void updateBITree(int index, int val);
			//void insertBITree(int val);
			int getSum(int index);
		};
	}
}
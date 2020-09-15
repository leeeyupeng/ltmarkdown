namespace lt {
	namespace tree
	{
		//BinaryIndexedTree
		class BITree_3 {
		private:
			int n;
			long long* _arr;
		public:
			BITree_3();
			~BITree_3();
			void init(int n);
			void updateBITree(int index, int val);
			//void insertBITree(int val);
			long long getSum(int index);
		};
	}
}
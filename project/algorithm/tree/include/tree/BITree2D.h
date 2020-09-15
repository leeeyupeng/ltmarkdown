namespace lt {
	namespace tree
	{
		//BinaryIndexedTree
		class BITree2D {
		private:
			int n,m;
			int* _arr;
		public:
			BITree2D();
			~BITree2D();
			void init(int _n,int _m);
			void updateBITree(int x,int y, int val);
			//void insertBITree(int val);
			int getSum(int x,int y);
		};
	}
}
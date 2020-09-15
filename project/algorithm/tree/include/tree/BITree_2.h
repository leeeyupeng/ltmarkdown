#include <unordered_map>
using namespace std;
namespace lt {
	namespace tree
	{
		//BinaryIndexedTree
		class BITree {
		private:
			unordered_map<int, int> map;
		public:
			void add(long long val);
			//void insertBITree(int val);
			int getSum(long long val);
		};
	}
}
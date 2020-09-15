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
			void add(int right, int val);
			int getMax(int left);
		};
	}
}
#include <iostream>
#include <assert.h>
using namespace std;
#define BYTE 8
template<int n>
class bitset
{
private:
	char* bits;
public:
	bitset() {
		int size = (n + (bytesize()-1))/ bytesize();
		bits = (char*)malloc(size);
		assert(bits != NULL);
		memset(bits,0x0,size);
	}
	void set(int index, bool v) {
		int index1 = index / bytesize();
		int index2 = index - index1 * bytesize();
		bits[index1] = v ? bits[index1] | (0x1 << index2): bits[index1] & ~(0x1 << index2);

	}
	bool test(int index) {
		int index1 = index / bytesize();
		int index2 = index - index1 * bytesize();
		return (bits[index1] & (0x1 << index2)) >> index2 == 0x1;
	}
	inline int bytesize()
	{
		return sizeof(char) * BYTE;
	}
	~bitset()
	{
		free(bits);
	}
};
#include <iostream>
#include<memory.h>
#include<limits.h>
using namespace std;
#include "tree/BITree_2.h"
void lt::tree::BITree::add(long long val) {
	long long index = (long long)val + INT_MAX + 1;
	while (index <= 2 * (long long)INT_MAX) {
		map[index] ++;
		index = index + (index & (-index));
	}
}
int lt::tree::BITree::getSum(long long val) {
	long long index = (long long)val + INT_MAX + 1;
	int result = 0;
	while (index > 0) {
		result += map[index];
		index = index - (index & (-index));
	}
	return result;
}
#include <iostream>
#include<memory.h>
#include<limits.h>
#include <algorithm>
using namespace std;
#include "tree/BITree_1.h"
void lt::tree::BITree::add(int right, int val) {
	long long index = right;
	index++;
	while (index > 0) {
		this->map[index] = max(this->map[index], val);
		index = index - (index & (-index));
	}
}

int lt::tree::BITree::getMax(int left) {
	long long index = left;
	index++;
	int result = 0;
	while (index <= INT_MAX) {
		result = max(result,this->map[index]);
		index = index + (index & (-index));
	}
	return result;
}
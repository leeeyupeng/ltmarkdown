#include <iostream>
#include<memory.h>
#include<limits.h>
using namespace std;
#include "tree/BITree.h"
lt::tree::BITree::BITree() {
}
lt::tree::BITree::~BITree(){
	free(_arr);
}
void lt::tree::BITree::init(int _n) {
	n = _n;
	_arr = (int*)malloc(sizeof(int) * (n + 1));
	memset(_arr, 0, sizeof(int) * (n + 1));
}
void lt::tree::BITree::updateBITree(int index, int val) {	
	index++;
	while (index <= n) {
		_arr[index] += val;
		index = index + (index & (-index));
	}
}
int lt::tree::BITree::getSum(int index) {
	index++;
	int result = 0;
	while (index > 0) {
		result += _arr[index];
		index = index - (index & (-index));
	}
	return result;
}
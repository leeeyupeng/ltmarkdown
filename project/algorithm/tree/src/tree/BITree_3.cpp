#include <iostream>
#include<memory.h>
#include<limits.h>
using namespace std;
#include "tree/BITree_3.h"
lt::tree::BITree_3::BITree_3() {
}
lt::tree::BITree_3::~BITree_3(){
	free(_arr);
}
void lt::tree::BITree_3::init(int _n) {
	n = _n;
	_arr = (long long*)malloc(sizeof(long long) * (n + 1));
	memset(_arr, 0, sizeof(long long) * (n + 1));
}
void lt::tree::BITree_3::updateBITree(int index, int val) {	
	index++;
	while (index <= n) {
		_arr[index] += val;
		index = index + (index & (-index));
	}
}
long long lt::tree::BITree_3::getSum(int index) {
	index++;
	long long result = 0;
	while (index > 0) {
		result += _arr[index];
		index = index - (index & (-index));
	}
	return result;
}